/* Constants for the TFMiniPlus fork */
#ifndef TFMINIPLUSCONST_FORK_H_
#define TFMINIPLUSCONST_FORK_H_

#define DATA_FRAME_MARKER 0x59
#define DATA_FRAME_LENGTH 9
#define CMD_FRAME_MARKER 0x5A
#define MAX_CMD_RESPONSE_LENGTH 8

constexpr uint8_t GetVersionCommand[4] = {CMD_FRAME_MARKER, 0x04, 0x01, 0x5F};
constexpr uint8_t ResetCommand[4] = {CMD_FRAME_MARKER, 0x04, 0x02, 0x60};
constexpr uint8_t TriggerDetectionCommand[4] = {CMD_FRAME_MARKER, 0X04, 0x04, 0x62};
constexpr uint8_t RestoreFactorySettingsCommand[4] = {CMD_FRAME_MARKER, 0x04, 0x10, 0x6E};
constexpr uint8_t SaveSettingsCommand[4] = {CMD_FRAME_MARKER, 0x04, 0x11, 0x6F};

#endif
