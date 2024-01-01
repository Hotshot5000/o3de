#pragma once
#include "GenericTransient.h"

namespace Hotshot::Net::ClientAPI::Tables
{
    class Map : public GenericTransient
    {
    private:
        AZ::u64 m_id = 0;
        AZ::u64 m_localId = 0;
        AZStd::string m_mapName = "";
        AZ::u32 m_teamBlueSpawnPoint = 0;
        AZ::u32 m_teamRedSpawnPoint = 0;

    public:
        AZ::u64 GetId() const
        {
            return m_id;
        }

        void SetId(AZ::u64 id)
        {
            m_id = id;
        }

        AZ::u64 GetLocalId() const
        {
            return m_localId;
        }

        void SetLocalId(AZ::u64 localId)
        {
            m_localId = localId;
        }

        AZStd::string GetMapName() const
        {
            return m_mapName;
        }

        void SetMapName(AZStd::string mapName)
        {
            m_mapName = mapName;
        }

        AZ::u32 GetTeamBlueSpawnPoint() const
        {
            return m_teamBlueSpawnPoint;
        }

        void SetTeamBlueSpawnPoint(AZ::u32 spawnPoint)
        {
            m_teamBlueSpawnPoint = spawnPoint;
        }

        AZ::u32 GetTeamRedSpawnPoint() const
        {
            return m_teamRedSpawnPoint;
        }

        void SetTeamRedSpawnPoint(AZ::u32 spawnPoint)
        {
            m_teamRedSpawnPoint = spawnPoint;
        }
    };
}
