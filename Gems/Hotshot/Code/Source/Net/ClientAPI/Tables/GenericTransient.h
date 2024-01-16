#pragma once
#include "AzCore/std/string/string.h"
#include "Net/ClientAPI/ErrorCodes.h"

namespace Hotshot::Net::ClientAPI::Tables
{
    class GenericTransient
    {
    private:
        AZStd::string m_error = "";
        AZ::u32 m_errorCode = Hotshot::Net::ClientAPI::ErrorCodes::NO_ERROR;

    public:
        AZStd::string GetError() const
        {
            return m_error;
        }

        void SetError(const AZStd::string& error)
        {
            this->m_error = error;
        }

        AZ::u32 GetErrorCode() const
        {
            return m_errorCode;
        }

        void SetErrorCode(AZ::u32 error_code)
        {
            m_errorCode = error_code;
        }
    };
}
