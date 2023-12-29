
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <Clients/HotshotSystemComponent.h>

namespace Hotshot
{
    /// System component for Hotshot editor
    class HotshotEditorSystemComponent
        : public HotshotSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = HotshotSystemComponent;
    public:
        AZ_COMPONENT_DECL(HotshotEditorSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        HotshotEditorSystemComponent();
        ~HotshotEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace Hotshot
