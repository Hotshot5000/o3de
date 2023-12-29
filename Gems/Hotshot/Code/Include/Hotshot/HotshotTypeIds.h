
#pragma once

namespace Hotshot
{
    // System Component TypeIds
    inline constexpr const char* HotshotSystemComponentTypeId = "{A8C8F62C-2DE3-49C5-A8A8-42C0C4F2D25E}";
    inline constexpr const char* HotshotEditorSystemComponentTypeId = "{DE21228F-DF03-4F37-8018-DFC3D1CDDABF}";

    // Module derived classes TypeIds
    inline constexpr const char* HotshotModuleInterfaceTypeId = "{1CFEE7AC-7C0D-42CD-AF3C-9ECAB2CE199E}";
    inline constexpr const char* HotshotModuleTypeId = "{76B2273D-7F50-4562-A7AC-B12F60CB22BF}";
    // The Editor Module by default is mutually exclusive with the Client Module
    // so they use the Same TypeId
    inline constexpr const char* HotshotEditorModuleTypeId = HotshotModuleTypeId;

    // Interface TypeIds
    inline constexpr const char* HotshotRequestsTypeId = "{E142C976-562A-4A28-B6D7-D7520490DDCA}";
} // namespace Hotshot
