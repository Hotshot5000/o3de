
#include <Hotshot/HotshotTypeIds.h>
#include <HotshotModuleInterface.h>
#include "HotshotSystemComponent.h"

namespace Hotshot
{
    class HotshotModule
        : public HotshotModuleInterface
    {
    public:
        AZ_RTTI(HotshotModule, HotshotModuleTypeId, HotshotModuleInterface);
        AZ_CLASS_ALLOCATOR(HotshotModule, AZ::SystemAllocator);
    };
}// namespace Hotshot

AZ_DECLARE_MODULE_CLASS(Gem_Hotshot, Hotshot::HotshotModule)
