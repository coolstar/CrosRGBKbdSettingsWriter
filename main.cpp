#include <cstdint>
#define UINT8 uint8_t
#define UINT16 uint16_t
#define UINT32 uint32_t
#define INT32 int32_t
#define USHORT uint16_t
#define ULONG uint32_t

#include <cstdbool>
#define BOOLEAN bool
#define TRUE true
#define FALSE false

#undef bool
#undef true
#undef false

#define RtlZeroMemory(Destination,Length) memset((Destination),0,(Length))
#define RtlCopyMemory memcpy

#undef memcpy
#undef memset

#define DbgPrint printf

#include <iostream>
#include <cassert>
#include "kblightsettings.h"

void osirisSettings() {
	UINT32 keyCount = 12;
	size_t sz = sizeof(CROSKBLIGHT_INFO) + keyCount * sizeof(CROSKBLIGHT_KEY_INFO);
	CROSKBLIGHT_INFO* kbLightInfo = (CROSKBLIGHT_INFO*)malloc(sz);
	if (kbLightInfo == NULL) {
		return;
	}
	RtlZeroMemory(kbLightInfo, sz);

	kbLightInfo->LampCount = keyCount;
	kbLightInfo->Width = 270000; //27 cm
	kbLightInfo->Height = 105000; //10.5 cm
	kbLightInfo->Depth = 300; //0.3 cm

	for (int i = 0; i < keyCount; i++) { //Common for all Keys
		kbLightInfo->Keys[i].RedCount = 255;
		kbLightInfo->Keys[i].GreenCount = 255;
		kbLightInfo->Keys[i].BlueCount = 255;
		kbLightInfo->Keys[i].IntensityCount = 1;
		kbLightInfo->Keys[i].IsProgrammable = 1;
	}

#define KEYSIZEW 53000 //5.2 cm
#define KEYSIZEH 52000 //5.1 cm

	UINT32 x = 0;
	for (int j = 0; j < 12;) {
		for (int i = 0; i < 3; i++) {
			j++;
			kbLightInfo->Keys[j].Pos_X = x + (KEYSIZEW * i);
			kbLightInfo->Keys[j].Pos_Y = KEYSIZEH * i;
			DbgPrint("Key %d: %d x %d\n", j, kbLightInfo->Keys[j].Pos_X, kbLightInfo->Keys[j].Pos_Y);
		}
		x += KEYSIZEW;
	}

	FILE* dumpedSettingsFile;
	if (fopen_s(&dumpedSettingsFile, "croskbrgb_generic_3.bin", "wb") == 0) {
		fwrite(kbLightInfo, 1, sz, dumpedSettingsFile);
		fclose(dumpedSettingsFile);

		DbgPrint("Wrote osiris settings to croskbrgb_generic_3.bin!\n");
	}
	else {
		DbgPrint("Warning: Failed to write settings for croskbrgblight (osiris)! Check that your permissions are correct!");
	}
	free(kbLightInfo);
}

void taniiksSettings() {
	UINT32 keyCount = 40;
	size_t sz = sizeof(CROSKBLIGHT_INFO) + keyCount * sizeof(CROSKBLIGHT_KEY_INFO);
	CROSKBLIGHT_INFO* kbLightInfo = (CROSKBLIGHT_INFO *)malloc(sz);
	if (kbLightInfo == NULL) {
		return;
	}
	RtlZeroMemory(kbLightInfo, sz);

	kbLightInfo->LampCount = keyCount;
	kbLightInfo->Width = 325000; //32.5 cm
	kbLightInfo->Height = 105000; //10.5 cm
	kbLightInfo->Depth = 300; //0.3 cm

	for (int i = 0; i < keyCount; i++) { //Common for all Keys
		kbLightInfo->Keys[i].RedCount = 255;
		kbLightInfo->Keys[i].GreenCount = 255;
		kbLightInfo->Keys[i].BlueCount = 255;
		kbLightInfo->Keys[i].IntensityCount = 1;
		kbLightInfo->Keys[i].IsProgrammable = 1;
	}

#define KEYSIZEW 32000 //3.2 cm
#define KEYSIZEH 25000 //2.5 cm

	UINT32 x = 0;
	for (int j = 0; j < 40;) {
		for (int i = 0; i < 4; i++) {
			j++;
			kbLightInfo->Keys[j].Pos_X = x + (KEYSIZEW * i);
			kbLightInfo->Keys[j].Pos_Y = KEYSIZEH * i;
			DbgPrint("Key %d: %d x %d\n", j, kbLightInfo->Keys[j].Pos_X, kbLightInfo->Keys[j].Pos_Y);
		}
		x += KEYSIZEW;
	}

	FILE* dumpedSettingsFile;
	if (fopen_s(&dumpedSettingsFile, "croskbrgb_generic_2.bin", "wb") == 0) {
		fwrite(kbLightInfo, 1, sz, dumpedSettingsFile);
		fclose(dumpedSettingsFile);

		DbgPrint("Wrote taniiks settings to croskbrgb_generic_2.bin!\n");
	}
	else {
		DbgPrint("Warning: Failed to write settings for croskbrgblight (taniiks)! Check that your permissions are correct!");
	}
	free(kbLightInfo);
}

void mithraxSettings() {
	UINT32 keyCount = 4;
	size_t sz = sizeof(CROSKBLIGHT_INFO) + keyCount * sizeof(CROSKBLIGHT_KEY_INFO);
	CROSKBLIGHT_INFO* kbLightInfo = (CROSKBLIGHT_INFO*)malloc(sz);
	if (kbLightInfo == NULL) {
		return;
	}
	RtlZeroMemory(kbLightInfo, sz);

	kbLightInfo->LampCount = keyCount;
	kbLightInfo->Width = 270000; //27 cm
	kbLightInfo->Height = 105000; //10.5 cm
	kbLightInfo->Depth = 300; //0.3 cm

	for (int i = 0; i < keyCount; i++) { //Common for all Keys
		kbLightInfo->Keys[i].RedCount = 255;
		kbLightInfo->Keys[i].GreenCount = 255;
		kbLightInfo->Keys[i].BlueCount = 255;
		kbLightInfo->Keys[i].IntensityCount = 1;
		kbLightInfo->Keys[i].IsProgrammable = 1;
	}

	for (int j = 0; j < 4; j++) {
		kbLightInfo->Keys[j].Pos_X = kbLightInfo->Width * j / 3;
		kbLightInfo->Keys[j].Pos_Y = kbLightInfo->Height / 2;
		DbgPrint("Key %d: %d x %d\n", j, kbLightInfo->Keys[j].Pos_X, kbLightInfo->Keys[j].Pos_Y);
	}

	FILE* dumpedSettingsFile;
	if (fopen_s(&dumpedSettingsFile, "croskbrgb_generic_4.bin", "wb") == 0) {
		fwrite(kbLightInfo, 1, sz, dumpedSettingsFile);
		fclose(dumpedSettingsFile);

		DbgPrint("Wrote osiris settings to croskbrgb_generic_4.bin!\n");
	}
	else {
		DbgPrint("Warning: Failed to write settings for croskbrgblight (mithrax)! Check that your permissions are correct!");
	}
	free(kbLightInfo);
}

int main() {
	osirisSettings();
	taniiksSettings();
	mithraxSettings();
	return 0;
}