LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/GameBackgroundLayer.cpp \
                   ../../Classes/PlaneLayer.cpp \
                   ../../Classes/BulletLayer.cpp \
                   ../../Classes/EnemyLayer.cpp \
                   ../../Classes/EnemyUserData.cpp \
                   ../../Classes/BulletUserData.cpp \
                   ../../Classes/PlaneUserData.cpp \
                   ../../Classes/ControlLayer.cpp \
                   ../../Classes/UFOLayer.cpp \
                   ../../Classes/UFOUserData.cpp \
                   ../../Classes/GameScene.cpp \
                   ../../Classes/ResultScene.cpp \
                   ../../Classes/WelcomeScene.cpp \
                   ../../Classes/WelcomeButtonLayer.cpp \
                   ../../Classes/ResultButtonLayer.cpp \
                   ../../Classes/WelcomeBackgroundLayer.cpp \
                   ../../Classes/ResultBackgroundLayer.cpp \
                   ../../Classes/EnemyBulletLayer.cpp \
                   ../../Classes/SelectScene.cpp \
                   ../../Classes/SelectButtonLayer.cpp \
                   ../../Classes/SelectBackgroundLayer.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
