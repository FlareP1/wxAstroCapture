/****************************************
 * ArtemisHSCAPI.h
 *
 * This file is autogenerated.
 * ...and modified by BM 20071228
****************************************/

#include <comdef.h>

//////////////////////////////////////////////////////////////////////////
//
// Interface functions for Artemis CCD Camera Library
//

// here we include the items mentioned to be moved (+some more)
#include "arttypes.h"

//Error codes

/* in arttypes.h now BM 20071228
enum ARTEMISERROR
{
	ARTEMIS_OK = 0,
	ARTEMIS_INVALID_PARAMETER,
	ARTEMIS_NOT_CONNECTED,
	ARTEMIS_NOT_IMPLEMENTED,
	ARTEMIS_NO_RESPONSE,
};
*/

/* in arttypes.h now BM 20071228
//Other enumeration types
enum ARTEMISPRECHARGEMODE
{
	PRECHARGE_NONE = 0,		// Precharge ignored
	PRECHARGE_ICPS,			// In-camera precharge subtraction
	PRECHARGE_FULL,			// Precharge sent with image data
};
*/

/* in arttypes.h now BM 20071228
// Camera State
enum ARTEMISCAMERASTATE
{
	CAMERA_ERROR = -1,
	CAMERA_IDLE = 0,
	CAMERA_WAITING,
	CAMERA_EXPOSING,
	CAMERA_READING,
	CAMERA_DOWNLOADING,
	CAMERA_FLUSHING,
};
*/

/* in arttypes.h now BM 20071228
// Parameters for ArtemisSendMessage
enum ARTEMISSENDMSG
{
	ARTEMIS_LE_LOW				=0,
	ARTEMIS_LE_HIGH				=1,
	ARTEMIS_GUIDE_NORTH			=10,
	ARTEMIS_GUIDE_SOUTH			=11,
	ARTEMIS_GUIDE_EAST			=12,
	ARTEMIS_GUIDE_WEST			=13,
	ARTEMIS_GUIDE_STOP			=14,
};
*/

/* in arttypes.h now BM 20071228
// Parameters for ArtemisGet/SetProcessing
// These must be powers of 2.
enum ARTEMISPROCESSING
{
	ARTEMIS_PROCESS_LINEARISE	=1,	// compensate for JFET nonlinearity
	ARTEMIS_PROCESS_VBE			=2, // adjust for 'Venetian Blind effect'
};
*/

/* in arttypes.h now BM 20071228
// Parameters for ArtemisSetUpADC
enum ARTEMISSETUPADC
{
	ARTEMIS_SETUPADC_MODE		=0,
	ARTEMIS_SETUPADC_OFFSETR	=(1<<10),
	ARTEMIS_SETUPADC_OFFSETG	=(2<<10),
	ARTEMIS_SETUPADC_OFFSETB	=(3<<10),
	ARTEMIS_SETUPADC_GAINR		=(4<<10),
	ARTEMIS_SETUPADC_GAING		=(5<<10),
	ARTEMIS_SETUPADC_GAINB		=(6<<10),
};
*/

/* in arttypes.h now BM 20071228
enum ARTEMISPROPERTIESCCDFLAGS
{
	ARTEMIS_PROPERTIES_CCDFLAGS_INTERLACED =1, // CCD is interlaced type
	ARTEMIS_PROPERTIES_CCDFLAGS_DUMMY=0x7FFFFFFF // force size to 4 bytes
};
*/

/* in arttypes.h now BM 20071228
enum ARTEMISPROPERTIESCAMERAFLAGS
{
	ARTEMIS_PROPERTIES_CAMERAFLAGS_FIFO =1, // Camera has readout FIFO fitted
	ARTEMIS_PROPERTIES_CAMERAFLAGS_EXT_TRIGGER =2, // Camera has external trigger capabilities
	ARTEMIS_PROPERTIES_CAMERAFLAGS_PREVIEW =4, // Camera can return preview data
	ARTEMIS_PROPERTIES_CAMERAFLAGS_SUBSAMPLE =8, // Camera can return subsampled data
	ARTEMIS_PROPERTIES_CAMERAFLAGS_DUMMY=0x7FFFFFFF // force size to 4 bytes
};
*/

//Structures

/* in arttypes.h now BM 20071228
// camera/CCD properties
struct ARTEMISPROPERTIES
{
	int Protocol;
	int nPixelsX;
	int nPixelsY;
	float PixelMicronsX;
	float PixelMicronsY;
	int ccdflags;
	int cameraflags;
	char Description[40];
	char Manufacturer[40];
};
*/

/* in arttypes.h now BM 20071228
typedef void* ArtemisHandle;
*/

// interface functions

// Return API version. XYY X=major, YY=minor
extern  int ArtemisHscAPIVersion();

// Get USB Identifier of Nth USB device. Return false if no such device.
// pName must be at least 40 chars long.
extern  bool ArtemisHscDeviceName(int Device, char *pName);

// Get USB Serial number of Nth USB device. Return false if no such device.
// pName must be at least 40 chars long.
extern  bool ArtemisHscDeviceSerial(int Device, char *pName);

// Return true if Nth USB device exists and is a camera.
extern  bool ArtemisHscDeviceIsCamera(int Device);

// Return camera type and serial number
// Low byte of flags is camera type, 1=4021, 2=11002
// Bits 8-31 of flags are reserved.
extern  int ArtemisHscCameraSerial(ArtemisHandle hCam, int* flags, int* serial);

// Disconnect from given device.
// Returns true if disconnected as requested
extern  bool ArtemisHscDisconnect(ArtemisHandle hCam);

// Connect to given device. If Device=-1, connect to first available
// Returns handle if connected as requested, else NULL
extern  ArtemisHandle ArtemisHscConnect(int Device);

// Disconnect all connected devices
extern  bool ArtemisHscDisconnectAll();

// Returns TRUE if currently connected to a device
extern  bool ArtemisHscIsConnected(ArtemisHandle hCam);

// Fills in pProp with camera properties
extern  int ArtemisHscProperties(ArtemisHandle hCam, struct ARTEMISPROPERTIES *pProp);

// Displays the Artemis setup dialog, if any
extern  int ArtemisHscSetupDialog();

// Abort exposure, if one is in progress
extern  int ArtemisHscAbortExposure(ArtemisHandle hCam);

// Set the start x,y coords for imaging subframe.
// X,Y in unbinned coordinates
extern  int ArtemisHscSubframePos(ArtemisHandle hCam, int x, int y);

// Set the width and height of imaging subframe
// W,H in unbinned coordinates
extern  int ArtemisHscSubframeSize(ArtemisHandle hCam, int w, int h);

// set the pos and size of imaging subframe inunbinned coords
extern  int ArtemisHscSubframe(ArtemisHandle hCam, int x, int y, int w, int h);

// Get the pos and size of imaging subframe
extern  int ArtemisHscGetSubframe(ArtemisHandle hCam, int *x, int *y, int *w, int *h);

// Set the x,y binning factors
extern  int ArtemisHscBin(ArtemisHandle hCam, int x, int y);

// Get the x,y binning factors
extern  int ArtemisHscGetBin(ArtemisHandle hCam, int *x, int *y);

// Get the maximum x,y binning factors
extern  int ArtemisHscGetMaxBin(ArtemisHandle hCam, int *x, int *y);

// Set the Precharge mode
extern  int ArtemisHscPrechargeMode(ArtemisHandle hCam, int mode);

// Clear the VRegs
extern  int ArtemisHscClearVRegs(ArtemisHandle hCam);

// Set the FIFO usage flag
extern  int ArtemisHscFIFO(ArtemisHandle hCam, bool bEnable);

// Start an exposure
extern  int ArtemisHscStartExposure(ArtemisHandle hCam, float Seconds);

// Prematurely end an exposure, collecting image data.
extern  int ArtemisHscStopExposure(ArtemisHandle hCam);

// Retrieve the downloaded image as a 2D array of type VARIANT
extern  int ArtemisHscGetImageArray(ArtemisHandle hCam, VARIANT *pImageArray);

// Retrieve image dimensions and binning factors.
// x,y are actual CCD locations. w,h are pixel dimensions of image
extern  int ArtemisHscGetImageData(ArtemisHandle hCam, int *x, int *y, int *w, int *h, int *binx, int *biny);

// Upload a compressed object file to the Artemis PIC
extern  int ArtemisHscReflash(ArtemisHandle hCam ,char *objfile);

// Return true if amp switched off during exposures
extern  bool ArtemisHscGetAmplifierSwitched(ArtemisHandle hCam);

// Set whether amp is switched off during exposures
extern  int ArtemisHscSetAmplifierSwitched(ArtemisHandle hCam, bool bSwitched);

// Return duration of last exposure, in seconds
extern  float ArtemisHscLastExposureDuration(ArtemisHandle hCam);

// Return time remaining in current exposure, in seconds
extern  float ArtemisHscExposureTimeRemaining(ArtemisHandle hCam);

// Return ptr to static buffer containing time of start of last exposure
extern  char* ArtemisHscLastStartTime(ArtemisHandle hCam);

// Return true if an image is ready to be retrieved
extern  bool ArtemisHscImageReady(ArtemisHandle hCam);

// Switch off all guide relays
extern  int ArtemisHscStopGuiding(ArtemisHandle hCam);

// Activate a guide relay for a short interval
extern  int ArtemisHscPulseGuide(ArtemisHandle hCam, int axis, int milli);

// Activate a guide relay
extern  int ArtemisHscGuide(ArtemisHandle hCam, int axis);

// Set download thread to high or normal priority
extern  int ArtemisHscHighPriority(ArtemisHandle hCam, bool bHigh);

// Retrieve the current camera state
extern  int ArtemisHscCameraState(ArtemisHandle hCam);

// Percentage downloaded
extern  int ArtemisHscDownloadPercent(ArtemisHandle hCam);

// Return pointer to internal image buffer (actually unsigned shorts)
extern  void* ArtemisHscImageBuffer(ArtemisHandle hCam);

// Set the CCD amplifier on or off
extern  int ArtemisHscAmplifier(ArtemisHandle hCam, bool bOn);

// Set the webcam Long Exposure control
extern  int ArtemisHscWebcamLE(ArtemisHandle hCam, bool bHigh);

// Reset the camera PIC
extern  int ArtemisHscReset(ArtemisHandle hCam);

// Get current image processing options
extern  int ArtemisHscGetProcessing(ArtemisHandle hCam);

// Set current image processing options
extern  int ArtemisHscSetProcessing(ArtemisHandle hCam, int options);

// Set External Trigger mode (if supported by camera). True=wait for trigger.
extern  int ArtemisHscTriggeredExposure(ArtemisHandle hCam, bool bAwaitTrigger);

// Set preview mode (if supported by camera). True=preview mode enabled.
extern  int ArtemisHscSetPreview(ArtemisHandle hCam, bool bPrev);

// Set subsampling mode (if supported by camera). True=subsampling enabled.
extern  int ArtemisHscSetSubSample(ArtemisHandle hCam, bool bSub);

// Send a packet of data to a peripheral, and receive a reply.
// pSendData points to an 8 byte array which is sent to the peripheral.
// pRecvData points to an 8 byte array which is filled with the peripheral's response.
// Returns ArtemisHsc_OK if the peripheral responds, in which case pRecvData contains its reply.
// Returns ARTEMIS_NO_RESPONSE if the peripheral doesn't respond.
// If the peripheral does not respond, pRecvData is not guaranteed to be preserved.
// pSendData and pRecvData may be the same but must not be NULL.
extern  int ArtemisHscPeripheral(ArtemisHandle hCam, int PeripheralID, unsigned char *pSendData, unsigned char *pRecvData);

// Set ADC parameters.
// param should be one of ARTEMISSETUPADC plus the data value
extern  int ArtemisHscSetUpADC(ArtemisHandle hCam, int param);

// Set conversion speed.
extern  int ArtemisHscSetConversionSpeed(ArtemisHandle hCam, int speed);

// Set conversion speed.
extern  int ArtemisHscSetOversample(ArtemisHandle hCam, int oversample);

extern  int ArtemisHscTemperatureSensorInfo(ArtemisHandle hCam, int sensor, int* temperature);

extern  int ArtemisHscCoolingInfo(ArtemisHandle hCam, int* flags, int* level, int* minlvl, int* maxlvl, int* setpoint);

extern  int ArtemisHscSetCooling(ArtemisHandle hCam, int setpoint);

extern  int ArtemisHscCoolerWarmUp(ArtemisHandle hCam);

extern  int ArtemisHscReconnectUSB(ArtemisHandle hCam);

/////////////////////////////////////////////////
// Diagnostic Functions

// Ping the camera, return the result. -1 on error.
extern  int ArtemisHscDiagnosticPing(ArtemisHandle hCam, int send);

// Ping the FIFO, return the result. -1 on error.
extern  int ArtemisHscDiagnosticPingFIFO(ArtemisHandle hCam, int send);

// Set the CCD clocks running (firmware doesn't return!)
extern  int ArtemisHscDiagnosticRunCCD(ArtemisHandle hCam);

// Measure the precharge level
extern  int ArtemisHscDiagnosticPrecharge(ArtemisHandle hCam);

// Connects to kernel only, safe to use before firmware
// has been uploaded.
// Returns handle if connected as requested
extern  ArtemisHandle ArtemisDiagnosticConnect(int Device);

// Miscellaneous commands to set voltages etc.
// Not to be called if the CCD is installed!
extern  int ArtemisHscDiagnosticCommand(ArtemisHandle hCam, int cmd);

// Return the last FT USB error condition seen
// Calling this function clears the internal error state
extern  int ArtemisHscDiagnosticUSBError(ArtemisHandle hCam);

/////////////////////////////////////////////////
// Access LE/Guide ports from 3rd-party software
// msg is the command to execute
// unit is the camera number
// returns:
//  0  OK
//  1  camera busy
//  2  no camera active
//  3  invalid command
extern  int ArtemisHscSendMessage(int msg, int unit);

/////////////////////////////////////////////////
// Access peripherals from 3rd-party software
// peripheral is the peripheral's device ID
// send and recv are 8-byte buffers for message-passing
// unit is the camera number
// returns:
//  0  OK
//  1  camera busy
//  2  no camera active
//  3  invalid command
//  4  no response fropm peripheral
extern  int ArtemisHscSendPeripheralMessage(int peripheral, char *send, char *recv, int unit);

/////////////////////////////////////////////////
// Get camera description, for 3rd-party software
// recv is a 40-byte buffer for the data
// info tells which data to return:
//  0  camera description from firmware
//  1  FTDI device name
//  2  FTDI device serial number
// unit is the camera number
// returns:
//  0  OK
//  1  camera busy
//  2  no camera active
extern  int ArtemisHscGetDescription(char *recv, int info, int unit);


// Try to load the Artemis DLL.
// Returns true if loaded ok.
extern bool ArtemisHscLoadDLL(char *FileName);

// Unload the Artemis DLL.
extern void ArtemisHscUnLoadDLL();

