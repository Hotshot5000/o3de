
#include "HotshotSystemComponent.h"

#include <Hotshot/HotshotTypeIds.h>

#include <AzCore/Serialization/SerializeContext.h>

namespace Hotshot
{
    AZ_COMPONENT_IMPL(HotshotSystemComponent, "HotshotSystemComponent",
        HotshotSystemComponentTypeId);

    void HotshotSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<HotshotSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void HotshotSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("HotshotService"));
    }

    void HotshotSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("HotshotService"));
    }

    void HotshotSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void HotshotSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    HotshotSystemComponent::HotshotSystemComponent()
    {
        if (HotshotInterface::Get() == nullptr)
        {
            HotshotInterface::Register(this);
        }
    }

    HotshotSystemComponent::~HotshotSystemComponent()
    {
        if (HotshotInterface::Get() == this)
        {
            HotshotInterface::Unregister(this);
        }
    }

    void HotshotSystemComponent::Init()
    {
    }

    void HotshotSystemComponent::Activate()
    {
        HotshotRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void HotshotSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        HotshotRequestBus::Handler::BusDisconnect();
    }

    void HotshotSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }

} // namespace Hotshot
