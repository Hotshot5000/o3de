
#pragma once

#include <AzCore/Component/ComponentBus.h>

namespace Hotshot
{
    class EntityPropertiesRequests
        : public AZ::ComponentBus
    {
    public:
        AZ_RTTI(Hotshot::EntityPropertiesRequests, "{B35BD544-E73B-455A-AB00-7186CA089E0B}");

        // Put your public request methods here.
        
        // Put notification events here. Examples:
        // void RegisterEvent(AZ::EventHandler<...> notifyHandler);
        // AZ::Event<...> m_notifyEvent1;
        
    };

    using EntityPropertiesRequestBus = AZ::EBus<EntityPropertiesRequests>;

} // namespace Hotshot
