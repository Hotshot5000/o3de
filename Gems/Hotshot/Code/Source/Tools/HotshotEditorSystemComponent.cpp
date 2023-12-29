
#include <AzCore/Serialization/SerializeContext.h>
#include "HotshotEditorSystemComponent.h"

#include <Hotshot/HotshotTypeIds.h>

namespace Hotshot
{
    AZ_COMPONENT_IMPL(HotshotEditorSystemComponent, "HotshotEditorSystemComponent",
        HotshotEditorSystemComponentTypeId, BaseSystemComponent);

    void HotshotEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<HotshotEditorSystemComponent, HotshotSystemComponent>()
                ->Version(0);
        }
    }

    HotshotEditorSystemComponent::HotshotEditorSystemComponent() = default;

    HotshotEditorSystemComponent::~HotshotEditorSystemComponent() = default;

    void HotshotEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("HotshotEditorService"));
    }

    void HotshotEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("HotshotEditorService"));
    }

    void HotshotEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void HotshotEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void HotshotEditorSystemComponent::Activate()
    {
        HotshotSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void HotshotEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        HotshotSystemComponent::Deactivate();
    }

} // namespace Hotshot
