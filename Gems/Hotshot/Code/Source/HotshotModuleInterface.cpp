
#include "HotshotModuleInterface.h"
#include <AzCore/Memory/Memory.h>

#include <Hotshot/HotshotTypeIds.h>

#include <Clients/HotshotSystemComponent.h>

namespace Hotshot
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(HotshotModuleInterface,
        "HotshotModuleInterface", HotshotModuleInterfaceTypeId);
    AZ_RTTI_NO_TYPE_INFO_IMPL(HotshotModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(HotshotModuleInterface, AZ::SystemAllocator);

    HotshotModuleInterface::HotshotModuleInterface()
    {
        // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
        // Add ALL components descriptors associated with this gem to m_descriptors.
        // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
        // This happens through the [MyComponent]::Reflect() function.
        m_descriptors.insert(m_descriptors.end(), {
            HotshotSystemComponent::CreateDescriptor(),
            });
    }

    AZ::ComponentTypeList HotshotModuleInterface::GetRequiredSystemComponents() const
    {
        return AZ::ComponentTypeList{
            azrtti_typeid<HotshotSystemComponent>(),
        };
    }
} // namespace Hotshot
