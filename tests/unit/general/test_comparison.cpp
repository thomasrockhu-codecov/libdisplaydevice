// local includes
#include "displaydevice/types.h"
#include "fixtures/fixtures.h"

namespace {
  // Specialized TEST macro(s) for this test file
#define TEST_S(...) DD_MAKE_TEST(TEST, TypeComparison, __VA_ARGS__)
}  // namespace

TEST_S(Point) {
  EXPECT_EQ(display_device::Point({ 1, 1 }), display_device::Point({ 1, 1 }));
  EXPECT_NE(display_device::Point({ 1, 1 }), display_device::Point({ 0, 1 }));
  EXPECT_NE(display_device::Point({ 1, 1 }), display_device::Point({ 1, 0 }));
}

TEST_S(Resolution) {
  EXPECT_EQ(display_device::Resolution({ 1, 1 }), display_device::Resolution({ 1, 1 }));
  EXPECT_NE(display_device::Resolution({ 1, 1 }), display_device::Resolution({ 0, 1 }));
  EXPECT_NE(display_device::Resolution({ 1, 1 }), display_device::Resolution({ 1, 0 }));
}

TEST_S(EnumeratedDevice, Info) {
  EXPECT_EQ(display_device::EnumeratedDevice::Info({ { 1, 1 }, 1.f, 1.f, true, { 1, 1 }, std::nullopt }),
    display_device::EnumeratedDevice::Info({ { 1, 1 }, 1.f, 1.f, true, { 1, 1 }, std::nullopt }));
  EXPECT_NE(display_device::EnumeratedDevice::Info({ { 1, 1 }, 1.f, 1.f, true, { 1, 1 }, std::nullopt }),
    display_device::EnumeratedDevice::Info({ { 1, 0 }, 1.f, 1.f, true, { 1, 1 }, std::nullopt }));
  EXPECT_NE(display_device::EnumeratedDevice::Info({ { 1, 1 }, 1.f, 1.f, true, { 1, 1 }, std::nullopt }),
    display_device::EnumeratedDevice::Info({ { 1, 1 }, 1.1f, 1.f, true, { 1, 1 }, std::nullopt }));
  EXPECT_NE(display_device::EnumeratedDevice::Info({ { 1, 1 }, 1.f, 1.f, true, { 1, 1 }, std::nullopt }),
    display_device::EnumeratedDevice::Info({ { 1, 1 }, 1.f, 1.1f, true, { 1, 1 }, std::nullopt }));
  EXPECT_NE(display_device::EnumeratedDevice::Info({ { 1, 1 }, 1.f, 1.f, true, { 1, 1 }, std::nullopt }),
    display_device::EnumeratedDevice::Info({ { 1, 1 }, 1.f, 1.f, false, { 1, 1 }, std::nullopt }));
  EXPECT_NE(display_device::EnumeratedDevice::Info({ { 1, 1 }, 1.f, 1.f, true, { 1, 1 }, std::nullopt }),
    display_device::EnumeratedDevice::Info({ { 1, 1 }, 1.f, 1.f, true, { 1, 0 }, std::nullopt }));
  EXPECT_NE(display_device::EnumeratedDevice::Info({ { 1, 1 }, 1.f, 1.f, true, { 1, 1 }, std::nullopt }),
    display_device::EnumeratedDevice::Info({ { 1, 1 }, 1.f, 1.f, true, { 1, 1 }, display_device::HdrState::Disabled }));
}

TEST_S(EnumeratedDevice) {
  EXPECT_EQ(display_device::EnumeratedDevice({ "1", "1", "1", display_device::EnumeratedDevice::Info {} }),
    display_device::EnumeratedDevice({ "1", "1", "1", display_device::EnumeratedDevice::Info {} }));
  EXPECT_NE(display_device::EnumeratedDevice({ "1", "1", "1", display_device::EnumeratedDevice::Info {} }),
    display_device::EnumeratedDevice({ "0", "1", "1", display_device::EnumeratedDevice::Info {} }));
  EXPECT_NE(display_device::EnumeratedDevice({ "1", "1", "1", display_device::EnumeratedDevice::Info {} }),
    display_device::EnumeratedDevice({ "1", "0", "1", display_device::EnumeratedDevice::Info {} }));
  EXPECT_NE(display_device::EnumeratedDevice({ "1", "1", "1", display_device::EnumeratedDevice::Info {} }),
    display_device::EnumeratedDevice({ "1", "1", "0", display_device::EnumeratedDevice::Info {} }));
  EXPECT_NE(display_device::EnumeratedDevice({ "1", "1", "1", display_device::EnumeratedDevice::Info {} }),
    display_device::EnumeratedDevice({ "1", "1", "1", std::nullopt }));
}

TEST_S(SingleDisplayConfiguration) {
  using DevicePrep = display_device::SingleDisplayConfiguration::DevicePreparation;
  EXPECT_EQ(display_device::SingleDisplayConfiguration({ "1", DevicePrep::EnsureActive, { { 1, 1 } }, 1.f, display_device::HdrState::Disabled }),
    display_device::SingleDisplayConfiguration({ "1", DevicePrep::EnsureActive, { { 1, 1 } }, 1.f, display_device::HdrState::Disabled }));
  EXPECT_NE(display_device::SingleDisplayConfiguration({ "1", DevicePrep::EnsureActive, { { 1, 1 } }, 1.f, display_device::HdrState::Disabled }),
    display_device::SingleDisplayConfiguration({ "0", DevicePrep::EnsureActive, { { 1, 1 } }, 1.f, display_device::HdrState::Disabled }));
  EXPECT_NE(display_device::SingleDisplayConfiguration({ "1", DevicePrep::EnsureActive, { { 1, 1 } }, 1.f, display_device::HdrState::Disabled }),
    display_device::SingleDisplayConfiguration({ "1", DevicePrep::EnsurePrimary, { { 1, 1 } }, 1.f, display_device::HdrState::Disabled }));
  EXPECT_NE(display_device::SingleDisplayConfiguration({ "1", DevicePrep::EnsureActive, { { 1, 1 } }, 1.f, display_device::HdrState::Disabled }),
    display_device::SingleDisplayConfiguration({ "1", DevicePrep::EnsureActive, { { 1, 0 } }, 1.f, display_device::HdrState::Disabled }));
  EXPECT_NE(display_device::SingleDisplayConfiguration({ "1", DevicePrep::EnsureActive, { { 1, 1 } }, 1.f, display_device::HdrState::Disabled }),
    display_device::SingleDisplayConfiguration({ "1", DevicePrep::EnsureActive, { { 1, 1 } }, 1.1f, display_device::HdrState::Disabled }));
  EXPECT_NE(display_device::SingleDisplayConfiguration({ "1", DevicePrep::EnsureActive, { { 1, 1 } }, 1.f, display_device::HdrState::Disabled }),
    display_device::SingleDisplayConfiguration({ "1", DevicePrep::EnsureActive, { { 1, 1 } }, 1.f, display_device::HdrState::Enabled }));
}