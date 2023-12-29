
#pragma once

#include <Hotshot/HotshotTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Hotshot
{
    class HotshotRequests
    {
    public:
        AZ_RTTI(HotshotRequests, HotshotRequestsTypeId);
        virtual ~HotshotRequests() = default;
        // Put your public methods here
    };

    class HotshotBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using HotshotRequestBus = AZ::EBus<HotshotRequests, HotshotBusTraits>;
    using HotshotInterface = AZ::Interface<HotshotRequests>;

} // namespace Hotshot
