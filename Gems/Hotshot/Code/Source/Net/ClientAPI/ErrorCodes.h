#pragma once
#include "AzCore/std/string/string.h"

namespace Hotshot::Net::ClientAPI::ErrorCodes
{

    AZ::u32 MINIMUM_USERNAME_LENGTH = 3;

    AZ::u32 MINIMUM_PASSWORD_LENGTH = 6;


    AZ::u32 NO_ERROR = 0;


    AZ::u32 LOGIN_INVALID = 1;

    AZStd::string LOGIN_INVALID_STR = "Invalid login";


    AZ::u32 ACCOUNT_ALREADY_EXISTS = 2;

    AZStd::string ACCOUNT_ALREADY_EXISTS_STR = "Account already exists";


    AZ::u32 SESSION_NAME_INVALID = 3;


    AZ::u32 SESSION_NAME_MULTIPLE = 4;


    AZ::u32 USER_ALREADY_IN_SESSION = 5;

    AZStd::string USER_ALREADY_IN_SESSION_STR = "User already in session";


    AZ::u32 SERVER_UNAVAILABLE = 6;

    AZStd::string SERVER_UNAVAILABLE_STR = "No server available";


    AZ::u32 TOKEN_INVALID = 7;

    AZStd::string TOKEN_INVALID_STR = "Invalid token";


    AZ::u32 TOKEN_EXPIRED = 8;

    AZStd::string TOKEN_EXPIRED_STR = "Token expired";


    AZ::u32 MAP_ALREADY_EXISTS = 9;

    AZStd::string MAP_ALREADY_EXISTS_STR = "Map name already exists";


    AZ::u32 SERVER_DOES_NOT_EXIST = 10;

    AZStd::string SERVER_DOES_NOT_EXIST_STR = "Server does not exist";


    AZ::u32 SERVER_INVALID = 11;

    AZStd::string SERVER_INVALID_STR = "Server invalid";


    AZ::u32 SESSION_INVALID_ID = 12;

    AZStd::string SESSION_INVALID_ID_STR = "Invalid id";


    AZ::u32 USER_NOT_IN_SESSION = 13;

    AZStd::string USER_NOT_IN_SESSION_STR = "User not in session";


    AZ::u32 ACCOUNT_DOES_NOT_EXIST = 14;

    AZStd::string ACCOUNT_DOES_NOT_EXIST_STR = "Account does not exist";


    AZ::u32 SERVER_GAME_TYPE_INCOMPATIBLE = 15;

    AZStd::string SERVER_GAME_TYPE_INCOMPATIBLE_STR =
        "Incompatible platforms connection attempt! You must be on the same platform type as the server.";


    AZ::u32 USER_FRIEND_ALREADY_EXISTS = 16;

    AZStd::string USER_FRIEND_ALREADY_EXISTS_STR = "Friend already added";


    AZ::u32 USER_FRIEND_NOT_FOUND = 17;

    AZStd::string USER_FRIEND_NOT_FOUND_STR = "Friend with that name cannot be found";


    AZ::u32 USER_FRIEND_TOO_MANY = 18;

    AZStd::string USER_FRIEND_TOO_MANY_STR = "Too many people found beginning with that name";


    AZ::u32 USER_FRIEND_ADDING_YOURSELF = 19;

    AZStd::string USER_FRIEND_ADDING_YOURSELF_STR = "You're trying to add yourself to the friend list :)";


    AZ::u32 ACCOUNT_USERNAME_TOO_SHORT = 20;

    AZStd::string ACCOUNT_USERNAME_TOO_SHORT_STR = "Your username must have at least " + MINIMUM_USERNAME_LENGTH + " characters";


    AZ::u32 ACCOUNT_PASSWORD_TOO_SHORT = 21;

    AZStd::string ACCOUNT_PASSWORD_TOO_SHORT_STR = "Your password must have at least " + MINIMUM_PASSWORD_LENGTH + " characters";


    AZ::u32 GET_FRIENDS_LIST_CANNOT_GET_FRIEND_STATUS = 22;

    AZStd::string GET_FRIENDS_LIST_CANNOT_GET_FRIEND_STATUS_STR = "Cannot get friend status";


    AZ::u32 ACCEPT_INVITATION_NO_INVITATION_PENDING = 23;

    AZStd::string ACCEPT_INVITATION_NO_INVITATION_PENDING_STR = "There is no invitation from that user";


    AZ::u32 ACCEPT_INVITATION_USER_NO_LONGER_AVAILABLE = 24;

    AZStd::string ACCEPT_INVITATION_USER_NO_LONGER_AVAILABLE_STR = "Cannot accept invitation of invalid player";


    AZ::u32 ACCEPT_INVITATION_COULD_NOT_NOTIFY_USER = 25;

    AZStd::string ACCEPT_INVITATION_COULD_NOT_NOTIFY_USER_STR = "Could not notify user of invitation acceptance";


    AZ::u32 GET_LOBBY_INVITATIONS_CANNOT_FIND_LOBBY = 26;

    AZStd::string GET_LOBBY_INVITATIONS_CANNOT_FIND_LOBBY_STR = "Could not find the lobby for your invitation";


    AZ::u32 GET_LOBBY_INVITATIONS_MULTIPLE_LOBBIES = 27;

    AZStd::string GET_LOBBY_INVITATIONS_MULTIPLE_LOBBIES_STR = "Multiple lobbies with the same id";


    AZ::u32 GET_LOBBY_STATUS_LOBBY_NOT_FOUND = 28;

    AZStd::string GET_LOBBY_STATUS_LOBBY_NOT_FOUND_STR = "Could not update lobby";


    AZ::u32 GET_LOBBY_STATUS_MULTIPLE_LOBBIES = 29;

    AZStd::string GET_LOBBY_STATUS_MULTIPLE_LOBBIES_STR = "Multiple lobbies with the same id";


    AZ::u32 GET_LOBBY_STATUS_NOBODY_INVITED = 30;

    AZStd::string GET_LOBBY_STATUS_NOBODY_INVITED_STR = "Nobody invited to the lobby";


    AZ::u32 JOIN_LOBBY_LOBBY_NOT_FOUND = 31;

    AZStd::string JOIN_LOBBY_LOBBY_NOT_FOUND_STR = "Could not update lobby";


    AZ::u32 JOIN_LOBBY_MULTIPLE_LOBBIES = 32;

    AZStd::string JOIN_LOBBY_MULTIPLE_LOBBIES_STR = "Multiple lobbies with the same id";


    AZ::u32 JOIN_LOBBY_CANNOT_FIND_INVITATION = 33;

    AZStd::string JOIN_LOBBY_CANNOT_FIND_INVITATION_STR = "Cannot find invitation";


    AZ::u32 JOIN_LOBBY_CANNOT_UPDATE_LOBBY_INVITATION = 34;

    AZStd::string JOIN_LOBBY_CANNOT_UPDATE_LOBBY_INVITATION_STR = "Cannot update the lobby invitation";


    AZ::u32 EXIT_LOBBY_LOBBY_NOT_FOUND = 35;

    AZStd::string EXIT_LOBBY_LOBBY_NOT_FOUND_STR = "Could not update lobby";


    AZ::u32 EXIT_LOBBY_MULTIPLE_LOBBIES = 36;

    AZStd::string EXIT_LOBBY_MULTIPLE_LOBBIES_STR = "Multiple lobbies with the same id";


    AZ::u32 EXIT_LOBBY_CANNOT_FIND_INVITATION = 37;

    AZStd::string EXIT_LOBBY_CANNOT_FIND_INVITATION_STR = "Cannot find invitation";


    AZ::u32 EXIT_LOBBY_CANNOT_UPDATE_LOBBY_INVITATION = 38;

    AZStd::string EXIT_LOBBY_CANNOT_UPDATE_LOBBY_INVITATION_STR = "Cannot update the lobby invitation";


    AZ::u32 EXIT_LOBBY_STATUS_NOBODY_INVITED = 39;

    AZStd::string EXIT_LOBBY_STATUS_NOBODY_INVITED_STR = "Nobody invited to the lobby";


    AZ::u32 EXIT_LOBBY_CANNOT_UPDATE_LOBBY_LEADER = 40;

    AZStd::string EXIT_LOBBY_CANNOT_UPDATE_LOBBY_LEADER_STR = "Cannot update lobby leader";


    AZ::u32 GET_LOBBY_INVITATIONS_NO_INVITATIONS = 41;

    AZStd::string GET_LOBBY_INVITATIONS_NO_INVITATIONS_STR = "No current invitations";
}
