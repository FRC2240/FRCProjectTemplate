#include <iostream>
#include "WPILib.h"
#include <ctrlib/CANTalon.h>
#include "PixyTracker.hpp"
#include <SmartDashboard/SmartDashboard.h>
#include "log.h"

#define _USE_MATH_DEFINES

const double PIXY_FIELD_OF_VIEW       = 47.0;
const double PIXY_IMAGE_HEIGHT_PIXELS = 240.0;
const double PIXY_IMAGE_WIDTH_PIXELS  = 360.0;

class Robot: public IterativeRobot
{
	// PixyCam Target Tracker
	PixyTracker  *m_pixy;

	std::string kLogLevel;

	enum RobotState {
		kOperatorControl,
		kSomethingAwesome,
		kSomethingMoreAwesome,
	} robotState = kOperatorControl;

	int stateTimer = 0;

	Preferences *prefs;

	// Read data from the Preferences Panel
	void getPreferences()
	{
		kLogLevel = prefs->GetString("kLogLevel", "INFO");

		Log::SetLevel(Log::FromString(kLogLevel));
		LOGGER(INFO) << "[getPreferences] kLogLevel:" << kLogLevel;
	}

	void stateOperatorControl()
	{
		LOGGER(DEBUG) << "[stateOperatorControl]";
	}

	void stateSomethingAwesome()
	{
		LOGGER(DEBUG) << "[stateSomethingAwesome]";
	}

	void stateSomethingMoreAwesome()
	{
		LOGGER(DEBUG) << "[stateSomethingMoreAwesome]";
	}

	//
	// RobotInit
	//
	void RobotInit()
	{
		LOGGER(DEBUG) << "[RobotInit]";

		prefs = Preferences::GetInstance();

		m_pixy = new PixyTracker();
		m_pixy->startVideo();
	}

	//
	// DisabledInit
	//
	void DisabledInit()
	{
		LOGGER(DEBUG) << "[DisabledInit]";

		getPreferences();
	}

	//
	// AutonomousInit
	//
	void AutonomousInit()
	{
		LOGGER(DEBUG) << "[AutonomousInit]";

		getPreferences();
	}
	//
	// TeleopInit
	//
	void TeleopInit()
	{
		LOGGER(DEBUG) << "[TeleopInit]";

		getPreferences();
	}

	//
	// TestInit
	//
	void TestInit()
	{
		LOGGER(DEBUG) << "[TestInit]";

		getPreferences();
	}


	//
	// RobotPeriodic
	//
	void RobotPeriodic()
	{
		LOGGER(DEBUG) << "[RobotPeriodic]";
	}

	//
	// DisabledPeriodic
	//
	void DisabledPeriodic()
	{
		LOGGER(DEBUG) << "[DisabledPeriodic]";
	}

	//
	// AutonomousPeriodic
	//
	void AutonomousPeriodic()
	{
		LOGGER(DEBUG) << "[AutonomousPeriodic]";
	}

	//
	// TeleopPeriodic
	//
	void TeleopPeriodic()
	{
		LOGGER(DEBUG) << "[TeleopPeriodic]";

		switch (robotState) {
		case kSomethingAwesome:
			stateSomethingAwesome();
			break;

		case kSomethingMoreAwesome:
			stateSomethingMoreAwesome();
			break;

		default:
		case kOperatorControl:
			stateOperatorControl();
			break;
		}
	}

	//
	// TestPeriodic
	//
	void TestPeriodic()
	{
		LOGGER(DEBUG) << "[TestPeriodic]";
	}
};

START_ROBOT_CLASS(Robot);
