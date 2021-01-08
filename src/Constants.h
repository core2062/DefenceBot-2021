#pragma once

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/trajectory/constraint/DifferentialDriveKinematicsConstraint.h>
#include <units/units.h>
#include <wpi/math>
// All of these values should be updated according to what works with the characterization tool


namespace DriveConstants {
constexpr auto kTrackwidth = 6545.5767404345215_m; // Not sure if this is correct or if we need to manually measure
extern const frc::DifferentialDriveKinematics kDriveKinematics;

constexpr int kEncoderCPR = 2048;
constexpr double kGearReduction = 15;
constexpr double kWheelDiameterInches = 6;
constexpr double kEncoderDistancePerPulse =
    // Assumes the encoders are directly mounted on the wheel shafts
    (kWheelDiameterInches * wpi::math::pi) / (static_cast<double>(kEncoderCPR) * kGearReduction);

constexpr bool kGyroReversed = true;

constexpr auto ks = 0.191_V;
constexpr auto kv = 0.000377 * 1_V * 1_s / 1_m;
constexpr auto ka = 2.67e-5 * 1_V * 1_s * 1_s / 1_m;

// Example value only - as above, this must be tuned for your drive!
constexpr double kPDriveVel = 8.5;
}  // namespace DriveConstants

namespace AutoConstants {
constexpr auto kMaxSpeed = 3_mps;
constexpr auto kMaxAcceleration = 3_mps_sq;

// Reasonable baseline values for a RAMSETE follower in units of meters and
// seconds
constexpr double kRamseteB = 2;
constexpr double kRamseteZeta = 0.7;
}  // namespace AutoConstants