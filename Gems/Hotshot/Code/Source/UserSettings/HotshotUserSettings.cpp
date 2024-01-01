#include "UserSettings/HotshotUserSettings.h"

#include "AzCore/Utils/Utils.h"
#include "AzFramework/FileFunc/FileFunc.h"
#include <AzCore/JSON/rapidjson.h>
#include <AzCore/JSON/document.h>     // rapidjson's DOM-style API
#include <AzCore/JSON/prettywriter.h> // for stringify JSON

namespace Hotshot
{
    using FixedString = AZStd::fixed_string<256>;

    // The base registry key that all our user settings will live underneath.
    // We keep them separate from the rest of the registry hierarchy to ensure that users can't
    // edit their settings file by hand to overwrite any other registry keys that weren't intentionally exposed.
    static constexpr FixedString BaseRegistryKey = "/O3DE/Hotshot/User/Settings";

    // These keep track of the specific registry keys used for each setting.
    static constexpr FixedString MultiplayerEnabledKey(BaseRegistryKey + FixedString("/MultiplayerEnabled"));
    static constexpr FixedString ShipSensitivityKey(BaseRegistryKey + FixedString("/"));
    static constexpr FixedString DataDownloadedKey(BaseRegistryKey + FixedString("/DataDownloaded"));
    static constexpr FixedString DataUnpackedKey(BaseRegistryKey + FixedString("/DataUnpacked"));
    static constexpr FixedString DataCopiedKey(BaseRegistryKey + FixedString("/DataCopied"));
    static constexpr FixedString LastShutdownSuccessfulKey(BaseRegistryKey + FixedString("/LastShutdownSuccessful"));
    static constexpr FixedString GameResourcesVersionKey(BaseRegistryKey + FixedString("/GameResourcesVersion"));
    static constexpr FixedString MapListKey(BaseRegistryKey + FixedString("/MapList"));
    static constexpr FixedString UserKey(BaseRegistryKey + FixedString("/User"));
    static constexpr FixedString MaxLevelReachedKey(BaseRegistryKey + FixedString("/MaxLevelReached"));
    static constexpr FixedString SoundsEnabledKey(BaseRegistryKey + FixedString("/SoundsEnabled"));
    static constexpr FixedString MusicEnabledKey(BaseRegistryKey + FixedString("/MusicEnabled"));
    static constexpr FixedString GyroEnabledKey(BaseRegistryKey + FixedString("/GyroEnabled"));
    static constexpr FixedString YInvertedKey(BaseRegistryKey + FixedString("/YInverted"));
    static constexpr FixedString ThirdPersonCameraKey(BaseRegistryKey + FixedString("/ThirdPersonCamera"));
    static constexpr FixedString VibrationEnabledKey(BaseRegistryKey + FixedString("/VibrationEnabled"));
}

Hotshot::UserSettings::UserSettings()
{
    m_registry = AZ::SettingsRegistry::Get();
    AZ_Assert(
        m_registry,
        "Initialization order incorrect, UserSettings has somehow started before "
        "the Settings Registry. Initial settings won't get applied correctly.");

    UserSettingsRequestBus::Handler::BusConnect();

    // Create a full path including filename for the user settings file.
    m_userSettingsPath = AZ::Utils::GetProjectUserPath();
    m_userSettingsPath /= "Registry";
    m_userSettingsPath /= "MultiplayerSampleUserSettings.setreg";

    // Load all of our settings keys, create default values if they don't exist and initialize the engine settings as appropriate.
    Load();
}

Hotshot::UserSettings::~UserSettings()
{
    UserSettingsRequestBus::Handler::BusDisconnect();

    // Always auto-save the user settings on destruction.
    Save();
}

void Hotshot::UserSettings::Load()
{
    // Read the setreg file from a loose file into a string in memory. This isn't technically a "cfg" file,
    // but the method does the exact set of steps needed here to read a loose file into memory, so even though
    // it has a slightly misleading name, it keeps us from duplicating the code.
    AZ::Outcome<AZStd::string, AZStd::string> userSettings =
        AzFramework::FileFunc::GetCfgFileContents(AZStd::string(m_userSettingsPath.FixedMaxPathString()));

    if (userSettings.IsSuccess())
    {
        // Merge the user settings file under the base "/O3DE/MultiplayerSample/User/Settings" key.
        // This will ensure that it cannot overwrite any other engine settings.
        // MergeSettings() is used here instead of MergeSettingsFile() because MergeSettingsFile() uses
        // FileIOBase to read in the file, which will attempt to read it from a PAK file in PAK file builds.
        // Our settings file will always be a loose file, so we instead read it into a buffer beforehand and then
        // apply it here from the in-memory buffer.
        [[maybe_unused]] auto mergeSuccess =
            m_registry->MergeSettings(userSettings.GetValue(), AZ::SettingsRegistryInterface::Format::JsonMergePatch, BaseRegistryKey);

        AZ_Error("UserSettings", mergeSuccess, "Failed to merge user settings into the O3DE registry.");
    }
}

void Hotshot::UserSettings::Save()
{
}

bool Hotshot::UserSettings::IsMultiplayerEnabled()
{
    bool multiplayerEnabled = false;
    m_registry->Get(multiplayerEnabled, MultiplayerEnabledKey.c_str());
    return multiplayerEnabled;
}

void Hotshot::UserSettings::SetMultiplayerEnabled(bool multiplayerEnabled)
{
    m_registry->Set(MultiplayerEnabledKey.c_str(), multiplayerEnabled);
}

float Hotshot::UserSettings::GetShipSensitivity()
{
    double shipSensitivity = 12.0f;
    m_registry->Get(shipSensitivity, ShipSensitivityKey.c_str());
    return aznumeric_cast<float>(shipSensitivity);
}

void Hotshot::UserSettings::SetShipSensitivity(float sensitivity)
{
    
    m_registry->Set(ShipSensitivityKey.c_str(), sensitivity);
}

bool Hotshot::UserSettings::IsDataDownloaded()
{
    bool dataDownloaded = false;
    m_registry->Get(dataDownloaded, DataDownloadedKey.c_str());
    return dataDownloaded;
}

void Hotshot::UserSettings::SetDataDownloaded(bool dataDownloaded)
{
    m_registry->Set(DataDownloadedKey.c_str(), dataDownloaded);
}

bool Hotshot::UserSettings::IsDataUnpacked()
{
    bool dataUnpacked = false;
    m_registry->Get(dataUnpacked, DataUnpackedKey.c_str());
    return dataUnpacked;
}

void Hotshot::UserSettings::SetDataUnpacked(bool dataUnpacked)
{
    m_registry->Set(DataUnpackedKey.c_str(), dataUnpacked);
}

bool Hotshot::UserSettings::IsDataCopied()
{
    bool dataCopied = false;
    m_registry->Get(dataCopied, DataCopiedKey.c_str());
    return dataCopied;
}

void Hotshot::UserSettings::SetDataCopied(bool dataCopied)
{
    m_registry->Set(DataCopiedKey.c_str(), dataCopied);
}

bool Hotshot::UserSettings::IsLastShutdownSuccessful()
{
    bool lastShutdownSuccessful = false;
    m_registry->Get(lastShutdownSuccessful, LastShutdownSuccessfulKey.c_str());
    return lastShutdownSuccessful;
}

void Hotshot::UserSettings::SetLastShutdownSuccessful(bool shutdownSuccessful)
{
    m_registry->Set(LastShutdownSuccessfulKey.c_str(), shutdownSuccessful);
}

AZ::u64 Hotshot::UserSettings::GetGameResourcesVersion()
{
    AZ::u64 gameResourcesVersion = -1;
    m_registry->Get(gameResourcesVersion, GameResourcesVersionKey.c_str());
    return gameResourcesVersion;
}

void Hotshot::UserSettings::SetGameResourcesVersion(AZ::u64 version)
{
    m_registry->Set(GameResourcesVersionKey.c_str(), version);
}

AZStd::vector<Hotshot::Map> Hotshot::UserSettings::GetMapList()
{
    AZStd::string jsonStr = "";
    m_registry->Get(jsonStr, MapListKey.c_str());

    AZStd::vector<Map> mapList;
    if (!jsonStr.empty())
    {
        rapidjson::Document document;
        if (!document.Parse(jsonStr.c_str()).HasParseError())
        {
            if (document.IsArray())
            {
                for(rapidjson::SizeType i = 0; i < document.Size(); ++i)
                {
                    Map map;
                    map.SetId(document[i]["id"].GetInt64());
                    map.SetLocalId(document[i]["localId"].GetInt64());
                    map.SetMapName(document[i]["mapName"].GetString());
                    map.SetTeamBlueSpawnPoint(document[i]["teamBlueSpawnPoint"].GetInt());
                    map.SetTeamRedSpawnPoint(document[i]["teamRedSpawnPoint"].GetInt());
                    mapList.push_back(map);
                }
            }
        }
    }
    return mapList;
}

void Hotshot::UserSettings::SetMapList(const AZStd::vector<Map>& mapList)
{
    rapidjson::Writer<rapidjson::StringBuffer> writer;
    writer.StartArray();

    for (const Map& map : mapList)
    {
        writer.StartObject();

        writer.String("id");
        writer.Int64(map.GetId());

        writer.String("localId");
        writer.Int64(map.GetLocalId());

        writer.String("mapName");
        writer.String(map.GetMapName().c_str());

        writer.String("teamBlueSpawnPoint");
        writer.Int(map.GetTeamBlueSpawnPoint());

        writer.String("teamRedSpawnPoint");
        writer.Int(map.GetTeamRedSpawnPoint());

        writer.EndObject();
    }

    writer.EndArray();

    rapidjson::Document document;
    document.Accept(writer);

    m_registry->Set(MapListKey.c_str(), document.GetString());
}

Hotshot::User Hotshot::UserSettings::GetUser()
{
    AZStd::string jsonStr = "";
    m_registry->Get(jsonStr, UserKey.c_str());

    User user;
    if (!jsonStr.empty())
    {
        rapidjson::Document document;
        if (!document.Parse(jsonStr.c_str()).HasParseError())
        {
            user.SetId(document["id"].GetInt64());
            user.SetUsername(document["username"].GetString());
            user.SetPassword(document["password"].GetString());
            user.SetSessionsPlayed(document["sessionsPlayed"].GetInt());
            user.SetSessionsWon(document["sessionsWon"].GetInt());
            user.SetSessionsLost(document["sessionsLost"].GetInt());
            user.SetKills(document["kills"].GetInt());
            user.SetDeaths(document["deaths"].GetInt());
            user.SetOnline(document["online"].GetInt());
            user.SetInSession(document["inSession"].GetInt());
            user.SetElo(document["elo"].GetInt());
            user.SetLastOnlineTime(document["lastOnlineTime"].GetInt64());
            user.SetLastInSessionTime(document["lastInSessionTime"].GetInt64());
            user.SetAuthToken(document["authToken"].GetString());
        }
    }
    return user;
}

void Hotshot::UserSettings::SetUser(const User& user)
{
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    writer.StartObject();

    writer.String("id");
    writer.Int64(user.GetId());

    writer.String("username");
    writer.String(user.GetUsername().c_str());

    writer.String("password");
    writer.String(user.GetPassword().c_str());

    writer.String("sessionsPlayed");
    writer.Int(user.GetSessionsPlayed());

    writer.String("sessionsWon");
    writer.Int(user.GetSessionsWon());

    writer.String("sessionsLost");
    writer.Int(user.GetSessionsLost());

    writer.String("kills");
    writer.Int(user.GetKills());

    writer.String("deaths");
    writer.Int(user.GetDeaths());

    writer.String("online");
    writer.Int(user.GetOnline());

    writer.String("inSession");
    writer.Int(user.GetInSession());

    writer.String("elo");
    writer.Int(user.GetElo());

    writer.String("lastOnlineTime");
    writer.Int64(user.GetLastOnlineTime());

    writer.String("lastInSessionTime");
    writer.Int64(user.GetLastInSessionTime());

    writer.String("authToken");
    writer.String(user.GetAuthToken().c_str());

    writer.EndObject();

    rapidjson::Document document;
    document.Accept(writer);

    m_registry->Set(UserKey.c_str(), document.GetString());
}

AZ::u32 Hotshot::UserSettings::GetMaxLevelReached()
{
    AZ::u64 maxLevelReached = 9;
    m_registry->Get(maxLevelReached, MaxLevelReachedKey.c_str());
    return aznumeric_cast<AZ::u32>(maxLevelReached);
}

void Hotshot::UserSettings::SetMaxLevelReached(AZ::u32 maxLevelReached)
{
    m_registry->Set(MaxLevelReachedKey.c_str(), aznumeric_cast<AZ::u64>(maxLevelReached));
}

bool Hotshot::UserSettings::GetSoundsEnabled()
{
    bool soundsEnabled = true;
    m_registry->Get(soundsEnabled, SoundsEnabledKey.c_str());
    return soundsEnabled;
}

void Hotshot::UserSettings::SetSoundsEnabled(bool soundsEnabled)
{
    m_registry->Set(SoundsEnabledKey.c_str(), soundsEnabled);
}

bool Hotshot::UserSettings::GetMusicEnabled()
{
    bool musicEnabled = true;
    m_registry->Get(musicEnabled, MusicEnabledKey.c_str());
    return musicEnabled;
}

void Hotshot::UserSettings::SetMusicEnabled(bool musicEnabled)
{
    m_registry->Set(MusicEnabledKey.c_str(), musicEnabled);
}

bool Hotshot::UserSettings::GetGyroEnabled()
{
    bool gyroEnabled = false;
    m_registry->Get(gyroEnabled, GyroEnabledKey.c_str());
    return gyroEnabled;
}

void Hotshot::UserSettings::SetGyroEnabled(bool gyroEnabled)
{
    m_registry->Set(GyroEnabledKey.c_str(), gyroEnabled);
}

bool Hotshot::UserSettings::GetYInverted()
{
    bool yInverted = false;
    m_registry->Get(yInverted, YInvertedKey.c_str());
    return yInverted;
}

void Hotshot::UserSettings::SetYInverted(bool yInverted)
{
    m_registry->Set(YInvertedKey.c_str(), yInverted);
}

bool Hotshot::UserSettings::GetThirdPersonCameraEnabled()
{
    bool thirdPersonCamera = false;
    m_registry->Get(thirdPersonCamera, ThirdPersonCameraKey.c_str());
    return thirdPersonCamera;
}

void Hotshot::UserSettings::SetThirdPersonCameraEnabled(bool thirdPersonCameraEnabled)
{
    m_registry->Set(ThirdPersonCameraKey.c_str(), thirdPersonCameraEnabled);
}

bool Hotshot::UserSettings::GetVibrationEnabled()
{
    bool vibrationEnabled = true;
    m_registry->Get(vibrationEnabled, VibrationEnabledKey.c_str());
    return vibrationEnabled;
}

void Hotshot::UserSettings::SetVibrationEnabled(bool vibrationEnabled)
{
    m_registry->Set(VibrationEnabledKey.c_str(), vibrationEnabled);
}
