
#include <Hotshot/HotshotTypeIds.h>
#include <HotshotModuleInterface.h>
#include "HotshotEditorSystemComponent.h"

namespace Hotshot
{
    class HotshotEditorModule
        : public HotshotModuleInterface
    {
    public:
        AZ_RTTI(HotshotEditorModule, HotshotEditorModuleTypeId, HotshotModuleInterface);
        AZ_CLASS_ALLOCATOR(HotshotEditorModule, AZ::SystemAllocator);

        HotshotEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                HotshotEditorSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<HotshotEditorSystemComponent>(),
            };
        }
    };
}// namespace Hotshot

AZ_DECLARE_MODULE_CLASS(Gem_Hotshot, Hotshot::HotshotEditorModule)
