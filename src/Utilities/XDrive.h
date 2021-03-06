/*
 * XDrive.h
 *
 *  Created on: Jan 25, 2018
 *      Author: TuffyPelly
 */

#ifndef SRC_XDRIVE_H_
#define SRC_XDRIVE_H_

#include <Drive/RobotDriveBase.h>
#include <memory>
#include <llvm/raw_ostream.h>
#include <ctre/Phoenix.h>
#include <string>

class XDrive: public frc::RobotDriveBase
{
private:
	WPI_TalonSRX	m_frontLeftMotor;
	WPI_TalonSRX	m_backLeftMotor;
	WPI_TalonSRX	m_frontRightMotor;
	WPI_TalonSRX	m_backRightMotor;

public:
	XDrive();
	~XDrive() override = default;

	// Drive robot via XDrive
	// Magnitude is 0 .. 1 for how fast to move
	// Total Angle is 0 .. 2 * Pi in radians for direction
	// Rotation is -1 .. 1
	void Drive(double magnitude, double totalAngle, double rotation);

	void StopMotor() override;
	void GetDescription(llvm::raw_ostream& desc) const override;

	void InitSendable(frc::SendableBuilder& builder) override;

	WPI_TalonSRX& Flm();
	WPI_TalonSRX& Frm();
	WPI_TalonSRX& Blm();
	WPI_TalonSRX& Brm();

private:
	void ConfigureMotorController(WPI_TalonSRX& motor, std::string name);
};

#endif /* SRC_XDRIVE_H_ */
