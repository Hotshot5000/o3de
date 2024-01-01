#pragma once
#include "Net/ClientAPI/Tables/Map.h"
#include "Net/ClientAPI/Tables/User.h"

#include <Atom/Bootstrap/BootstrapNotificationBus.h>
#include <AzCore/EBus/EBus.h>
#include <AzCore/IO/Path/Path.h>

namespace AZ
{
    class SettingsRegistryInterface;
}

namespace Hotshot
{
    using namespace Hotshot::Net::ClientAPI::Tables;
    class UserSettingsRequests : public AZ::EBusTraits
    {
    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;

        virtual ~UserSettingsRequests() = default;

        virtual void Load() = 0;
        virtual void Save() = 0;

        virtual bool IsMultiplayerEnabled() = 0;
        virtual void SetMultiplayerEnabled(bool multiplayerEnabled) = 0;

        virtual float GetShipSensitivity() = 0;
        virtual void SetShipSensitivity(float sensitivity) = 0;

        virtual bool IsDataDownloaded() = 0;
        virtual void SetDataDownloaded(bool dataDownloaded) = 0;

        virtual bool IsDataUnpacked() = 0;
        virtual void SetDataUnpacked(bool dataUnpacked) = 0;

        virtual bool IsDataCopied() = 0;
        virtual void SetDataCopied(bool dataCopied) = 0;

        virtual bool IsLastShutdownSuccessful() = 0;
        virtual void SetLastShutdownSuccessful(bool shutdownSuccessful) = 0;

        virtual AZ::u64 GetGameResourcesVersion() = 0;
        virtual void SetGameResourcesVersion(AZ::u64 version) = 0;

        virtual AZStd::vector<Map> GetMapList() = 0;
        virtual void SetMapList(const AZStd::vector<Map>& mapList) = 0;

        virtual User GetUser() = 0;
        virtual void SetUser(const User& user) = 0;

        virtual AZ::u32 GetMaxLevelReached() = 0;
        virtual void SetMaxLevelReached(AZ::u32 maxLevelReached) = 0;

        virtual bool GetSoundsEnabled() = 0;
        virtual void SetSoundsEnabled(bool soundsEnabled) = 0;

        virtual bool GetMusicEnabled() = 0;
        virtual void SetMusicEnabled(bool musicEnabled) = 0;

        virtual bool GetGyroEnabled() = 0;
        virtual void SetGyroEnabled(bool gyroEnabled) = 0;

        virtual bool GetYInverted() = 0;
        virtual void SetYInverted(bool yInverted) = 0;

        virtual bool GetThirdPersonCameraEnabled() = 0;
        virtual void SetThirdPersonCameraEnabled(bool thirdPersonCameraEnabled) = 0;

        virtual bool GetVibrationEnabled() = 0;
        virtual void SetVibrationEnabled(bool vibrationEnabled) = 0;
    };

    using UserSettingsRequestBus = AZ::EBus<UserSettingsRequests>;

    class UserSettings : public UserSettingsRequestBus::Handler
    {
    public:
        UserSettings();
        ~UserSettings() override;

        void Load() override;
        void Save() override;

        bool IsMultiplayerEnabled() override;
        void SetMultiplayerEnabled(bool multiplayerEnabled) override;
        float GetShipSensitivity() override;
        void SetShipSensitivity(float sensitivity) override;
        bool IsDataDownloaded() override;
        void SetDataDownloaded(bool dataDownloaded) override;
        bool IsDataUnpacked() override;
        void SetDataUnpacked(bool dataUnpacked) override;
        bool IsDataCopied() override;
        void SetDataCopied(bool dataCopied) override;
        bool IsLastShutdownSuccessful() override;
        void SetLastShutdownSuccessful(bool shutdownSuccessful) override;
        AZ::u64 GetGameResourcesVersion() override;
        void SetGameResourcesVersion(AZ::u64 version) override;
        AZStd::vector<Map> GetMapList() override;
        void SetMapList(const AZStd::vector<Map>& mapList) override;
        User GetUser() override;
        void SetUser(const User& user) override;
        AZ::u32 GetMaxLevelReached() override;
        void SetMaxLevelReached(AZ::u32 maxLevelReached) override;
        bool GetSoundsEnabled() override;
        void SetSoundsEnabled(bool soundsEnabled) override;
        bool GetMusicEnabled() override;
        void SetMusicEnabled(bool musicEnabled) override;
        bool GetGyroEnabled() override;
        void SetGyroEnabled(bool gyroEnabled) override;
        bool GetYInverted() override;
        void SetYInverted(bool yInverted) override;
        bool GetThirdPersonCameraEnabled() override;
        void SetThirdPersonCameraEnabled(bool thirdPersonCameraEnabled) override;
        bool GetVibrationEnabled() override;
        void SetVibrationEnabled(bool vibrationEnabled) override;

    private:
        // Cached pointer to the settings registry so that we don't have to fetch it for every setting.
        AZ::SettingsRegistryInterface* m_registry = nullptr;

        // The path to the user settings file.
        AZ::IO::FixedMaxPath m_userSettingsPath;
    };
    
}
