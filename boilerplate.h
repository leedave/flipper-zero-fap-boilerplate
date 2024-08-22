#pragma once

#include <furi.h>
#include <furi_hal.h>
#include <gui/gui.h>
#include <input/input.h>
#include <stdlib.h>
#include <dialogs/dialogs.h>
#include <notification/notification_messages.h>
#include <gui/view_dispatcher.h>
#include <gui/modules/submenu.h>
#include <gui/scene_manager.h>
#include <gui/modules/variable_item_list.h>
#include <gui/modules/button_menu.h>
#include <gui/modules/number_input.h>
#include <gui/modules/text_input.h>
#include "scenes/boilerplate_scene.h"
#include "views/boilerplate_startscreen.h"
#include "views/boilerplate_scene_1.h"
#include "views/boilerplate_scene_2.h"
#include "helpers/boilerplate_storage.h"
#include "boilerplate_icons.h"

#define TAG "Boilerplate"

#define SUBGHZ_APP_EXTENSION ".sub"
#define SUBGHZ_APP_FOLDER ANY_PATH("subghz")
#define BOILERPLATE_VERSION "1.3"
#define BOILERPLATE_TEXT_STORE_SIZE 128
#define BOILERPLATE_TEXT_STORE_COUNT 3

typedef struct {
    Gui* gui;
    NotificationApp* notification;
    ViewDispatcher* view_dispatcher;
    Submenu* submenu;
    SceneManager* scene_manager;
    VariableItemList* variable_item_list;
    BoilerplateStartscreen* boilerplate_startscreen;
    BoilerplateScene1* boilerplate_scene_1;
    BoilerplateScene2* boilerplate_scene_2;
    DialogsApp* dialogs; // File Browser
    FuriString* file_path; // File Browser
    uint32_t haptic;
    uint32_t speaker;
    uint32_t led;
    uint32_t save_settings;
    ButtonMenu* button_menu; // Button Menu
    NumberInput* number_input;
    int32_t current_number;
    TextInput* text_input;
    char text_store[BOILERPLATE_TEXT_STORE_COUNT][BOILERPLATE_TEXT_STORE_SIZE + 1];
} Boilerplate;

typedef enum {
    BoilerplateViewIdStartscreen,
    BoilerplateViewIdMenu,
    BoilerplateViewIdScene1,
    BoilerplateViewIdScene2,
    BoilerplateViewIdScene3,
    BoilerplateViewIdTextInput,
    BoilerplateViewIdNumberInput,
    BoilerplateViewIdSettings,
} BoilerplateViewId;

typedef enum {
    BoilerplateHapticOff,
    BoilerplateHapticOn,
} BoilerplateHapticState;

typedef enum {
    BoilerplateSpeakerOff,
    BoilerplateSpeakerOn,
} BoilerplateSpeakerState;

typedef enum {
    BoilerplateLedOff,
    BoilerplateLedOn,
} BoilerplateLedState;

typedef enum {
    BoilerplateSettingsOff,
    BoilerplateSettingsOn,
} BoilerplateSettingsStoreState;
