#pragma once
#include "GenericTransient.h"

namespace Hotshot::Net::ClientAPI::Tables
{
    class User : public GenericTransient
    {
    private:
        AZ::u64 m_id = 0;
        AZStd::string m_username = "";
        AZStd::string m_password = "";
        AZ::u32 m_sessionsPlayed = 0;
        AZ::u32 m_sessionsWon = 0;
        AZ::u32 m_sessionsLost = 0;
        AZ::u32 m_kills = 0;
        AZ::u32 m_deaths = 0;
        AZ::u32 m_online = 0;
        AZ::u32 m_inSession = 0;
        AZ::u32 m_elo = 0;
        AZ::u64 m_lastOnlineTime = 0;
        AZ::u64 m_lastInSessionTime = 0;
        AZStd::string m_authToken = "";

    public:
        AZ::u64 GetId() const
        {
            return m_id;
        }

        void SetId(AZ::u64 id)
        {
            this->m_id = id;
        }

        AZStd::string GetUsername() const
        {
            return m_username;
        }

        void SetUsername(const AZStd::string& username)
        {
            this->m_username = username;
        }

        AZStd::string GetPassword() const
        {
            return m_password;
        }

        void SetPassword(const AZStd::string& password)
        {
            this->m_password = password;
        }

        AZ::u32 GetSessionsPlayed() const
        {
            return m_sessionsPlayed;
        }

        void SetSessionsPlayed(AZ::u32 sessions_played)
        {
            m_sessionsPlayed = sessions_played;
        }

        AZ::u32 GetSessionsWon() const
        {
            return m_sessionsWon;
        }

        void SetSessionsWon(AZ::u32 sessions_won)
        {
            m_sessionsWon = sessions_won;
        }

        AZ::u32 GetSessionsLost() const
        {
            return m_sessionsLost;
        }

        void SetSessionsLost(AZ::u32 sessions_lost)
        {
            m_sessionsLost = sessions_lost;
        }

        AZ::u32 GetKills() const
        {
            return m_kills;
        }

        void SetKills(AZ::u32 kills)
        {
            this->m_kills = kills;
        }

        AZ::u32 GetDeaths() const
        {
            return m_deaths;
        }

        void SetDeaths(AZ::u32 deaths)
        {
            this->m_deaths = deaths;
        }

        AZ::u32 GetOnline() const
        {
            return m_online;
        }

        void SetOnline(AZ::u32 online)
        {
            this->m_online = online;
        }

        AZ::u32 GetInSession() const
        {
            return m_inSession;
        }

        void SetInSession(AZ::u32 in_session)
        {
            m_inSession = in_session;
        }

        AZ::u32 GetElo() const
        {
            return m_elo;
        }

        void SetElo(AZ::u32 elo)
        {
            this->m_elo = elo;
        }

        AZ::u64 GetLastOnlineTime() const
        {
            return m_lastOnlineTime;
        }

        void SetLastOnlineTime(AZ::u64 last_online_time)
        {
            m_lastOnlineTime = last_online_time;
        }

        AZ::u64 GetLastInSessionTime() const
        {
            return m_lastInSessionTime;
        }

        void SetLastInSessionTime(AZ::u64 last_in_session_time)
        {
            m_lastInSessionTime = last_in_session_time;
        }

        AZStd::string GetAuthToken() const
        {
            return m_authToken;
        }

        void SetAuthToken(const AZStd::string& auth_token)
        {
            m_authToken = auth_token;
        }
    };
}
