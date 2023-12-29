
#include <EntityPropertiesComponent.h>

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/RTTI/BehaviorContext.h>

namespace Hotshot
{
    AZ_COMPONENT_IMPL(EntityPropertiesComponent, "EntityPropertiesComponent", "{7F88AEEE-1B23-47A2-B50F-3B998AD7997A}");

    void EntityPropertiesComponent::Activate()
    {
        EntityPropertiesRequestBus::Handler::BusConnect(GetEntityId());
    }

    void EntityPropertiesComponent::Deactivate()
    {
        EntityPropertiesRequestBus::Handler::BusDisconnect(GetEntityId());
    }

    void EntityPropertiesComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<EntityPropertiesComponent, AZ::Component>()
                ->Version(1)
                ;

            if (AZ::EditContext* editContext = serializeContext->GetEditContext())
            {
                editContext->Class<EntityPropertiesComponent>("EntityPropertiesComponent", "[Description of functionality provided by this component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    ->Attribute(AZ::Edit::Attributes::Category, "ComponentCategory")
                    ->Attribute(AZ::Edit::Attributes::Icon, "Icons/Components/Component_Placeholder.svg")
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC_CE("Game"))
                    ;
            }
        }

        if (AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context))
        {
            behaviorContext->Class<EntityPropertiesComponent>("EntityProperties Component Group")
                ->Attribute(AZ::Script::Attributes::Category, "Hotshot Gem Group")
                ;
        }
    }

    void EntityPropertiesComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("EntityPropertiesComponentService"));
    }

    void EntityPropertiesComponent::GetIncompatibleServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
    }

    void EntityPropertiesComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void EntityPropertiesComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
} // namespace Hotshot
