/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/**
* @file RBAC.h
* @brief Role Based Access Control related classes definition
*
* This file contains all the classes and enums used to implement
* Role Based Access Control
*
* RBAC Rules:
* - Pemission: Defines an autorization to perform certain operation.
* - Role: Set of permissions.
* - Group: Set of roles.
* - An Account can have multiple groups, roles and permissions.
* - Account Groups can only be granted or revoked
* - Account Roles and Permissions can be granted, denied or revoked
* - Grant: Assignment of the object (role/permission) and allow it
* - Deny: Assignment of the object (role/permission) and deny it
* - Revoke: Removal of the object (role/permission) no matter if it was granted or denied
* - Global Permissions are computed as:
*       Group Grants + Role Grants + User Grans - Role Grants - User Grants
* - Groups, Roles and Permissions can be assigned by realm
*/

#ifndef _RBAC_H
#define _RBAC_H

#include "Define.h"
#include <string>
#include <bitset>
#include <set>
#include <map>

enum RBACPermissions
{
    RBAC_PERM_INSTANT_LOGOUT                                 = 1,
    RBAC_PERM_SKIP_QUEUE                                     = 2,
    RBAC_PERM_JOIN_NORMAL_BG                                 = 3,
    RBAC_PERM_JOIN_RANDOM_BG                                 = 4,
    RBAC_PERM_JOIN_ARENAS                                    = 5,
    RBAC_PERM_JOIN_DUNGEON_FINDER                            = 6,
    RBAC_PERM_PLAYER_COMMANDS                                = 7,
    RBAC_PERM_MODERATOR_COMMANDS                             = 8,
    RBAC_PERM_GAMEMASTER_COMMANDS                            = 9,
    RBAC_PERM_ADMINISTRATOR_COMMANDS                         = 10,
    RBAC_PERM_LOG_GM_TRADE                                   = 11,
    RBAC_PERM_CONSOLE_COMMANDS                               = 12, // Not pressent in DB
    RBAC_PERM_SKIP_CHECK_INSTANCE_REQUIRED_BOSSES            = 13,
    RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_TEAMMASK         = 14,
    RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_CLASSMASK        = 15,
    RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RACEMASK         = 16,
    RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_RESERVEDNAME     = 17,
    RBAC_PERM_SKIP_CHECK_CHARACTER_CREATION_HEROIC_CHARACTER = 18,
    RBAC_PERM_SKIP_CHECK_CHAT_CHANNEL_REQ                    = 19,
    RBAC_PERM_SKIP_CHECK_DISABLE_MAP                         = 20,
    RBAC_PERM_SKIP_CHECK_MORE_TALENTS_THAN_ALLOWED           = 21,
    RBAC_PERM_SKIP_CHECK_CHAT_SPAM                           = 22,
    RBAC_PERM_SKIP_CHECK_OVERSPEED_PING                      = 23,
    RBAC_PERM_TWO_SIDE_CHARACTER_CREATION                    = 24,
    RBAC_PERM_TWO_SIDE_INTERACTION_CHAT                      = 25,
    RBAC_PERM_TWO_SIDE_INTERACTION_CHANNEL                   = 26,
    RBAC_PERM_TWO_SIDE_INTERACTION_MAIL                      = 27,
    RBAC_PERM_TWO_SIDE_WHO_LIST                              = 28,
    RBAC_PERM_TWO_SIDE_ADD_FRIEND                            = 29,
    RBAC_PERM_COMMANDS_SAVE_WITHOUT_DELAY                    = 30,
    RBAC_PERM_COMMANDS_USE_UNSTUCK_WITH_ARGS                 = 31,
    RBAC_PERM_COMMANDS_BE_ASSIGNED_TICKET                    = 32,
    RBAC_PERM_COMMANDS_NOTIFY_COMMAND_NOT_FOUND_ERROR        = 33,
    RBAC_PERM_COMMANDS_APPEAR_IN_GM_LIST                     = 34,
    RBAC_PERM_WHO_SEE_ALL_SEC_LEVELS                         = 35,
    RBAC_PERM_CAN_FILTER_WHISPERS                            = 36,
    RBAC_PERM_CHAT_USE_STAFF_BADGE                           = 37,
    RBAC_PERM_RESURRECT_WITH_FULL_HPS                        = 38,
    RBAC_PERM_RESTORE_SAVED_GM_STATE                         = 39,
    RBAC_PERM_ALLOW_GM_FRIEND                                = 40,
    RBAC_PERM_USE_START_GM_LEVEL                             = 41,
    RBAC_PERM_OPCODE_WORLD_TELEPORT                          = 42,
    RBAC_PERM_OPCODE_WHOIS                                   = 43,
    RBAC_PERM_RECEIVE_GLOBAL_GM_TEXTMESSAGE                  = 44,
    RBAC_PERM_SILENTLY_JOIN_CHANNEL                          = 45,
    RBAC_PERM_CHANGE_CHANNEL_NOT_MODERATOR                   = 46,
    RBAC_PERM_CHECK_FOR_LOWER_SECURITY                       = 47,
    RBAC_PERM_COMMANDS_PINFO_CHECK_PERSONAL_DATA             = 48,
    // Leave some space for core permissions
    RBAC_PERM_COMMAND_RBAC                                   = 200,
    RBAC_PERM_COMMAND_RBAC_ACC                               = 201,
    RBAC_PERM_COMMAND_RBAC_ACC_GROUP                         = 202,
    RBAC_PERM_COMMAND_RBAC_ACC_GROUP_ADD                     = 203,
    RBAC_PERM_COMMAND_RBAC_ACC_GROUP_DEL                     = 204,
    RBAC_PERM_COMMAND_RBAC_ACC_ROLE                          = 205,
    RBAC_PERM_COMMAND_RBAC_ACC_ROLE_GRANT                    = 206,
    RBAC_PERM_COMMAND_RBAC_ACC_ROLE_DENY                     = 207,
    RBAC_PERM_COMMAND_RBAC_ACC_ROLE_REVOKE                   = 208,
    RBAC_PERM_COMMAND_RBAC_ACC_PERM                          = 209,
    RBAC_PERM_COMMAND_RBAC_ACC_PERM_GRANT                    = 210,
    RBAC_PERM_COMMAND_RBAC_ACC_PERM_DENY                     = 211,
    RBAC_PERM_COMMAND_RBAC_ACC_PERM_REVOKE                   = 212,
    RBAC_PERM_COMMAND_RBAC_LIST                              = 213,
    RBAC_PERM_COMMAND_RBAC_LIST_GROUPS                       = 214,
    RBAC_PERM_COMMAND_RBAC_LIST_ROLES                        = 215,
    RBAC_PERM_COMMAND_RBAC_LIST_PERMS                        = 216,
    RBAC_PERM_COMMAND_ACCOUNT                                = 217,
    RBAC_PERM_COMMAND_ACCOUNT_ADDON                          = 218,
    RBAC_PERM_COMMAND_ACCOUNT_CREATE                         = 219,
    RBAC_PERM_COMMAND_ACCOUNT_DELETE                         = 220,
    RBAC_PERM_COMMAND_ACCOUNT_LOCK                           = 221,
    RBAC_PERM_COMMAND_ACCOUNT_LOCK_COUNTRY                   = 222,
    RBAC_PERM_COMMAND_ACCOUNT_LOCK_IP                        = 223,
    RBAC_PERM_COMMAND_ACCOUNT_ONLINE_LIST                    = 224,
    RBAC_PERM_COMMAND_ACCOUNT_PASSWORD                       = 225,
    RBAC_PERM_COMMAND_ACCOUNT_SET                            = 226,
    RBAC_PERM_COMMAND_ACCOUNT_SET_ADDON                      = 227,
    RBAC_PERM_COMMAND_ACCOUNT_SET_GMLEVEL                    = 228,
    RBAC_PERM_COMMAND_ACCOUNT_SET_PASSWORD                   = 229,
    RBAC_PERM_COMMAND_ACHIEVEMENT                            = 230,
    RBAC_PERM_COMMAND_ACHIEVEMENT_ADD                        = 231,
    RBAC_PERM_COMMAND_ARENA                                  = 232,
    RBAC_PERM_COMMAND_ARENA_CAPTAIN                          = 233,
    RBAC_PERM_COMMAND_ARENA_CREATE                           = 234,
    RBAC_PERM_COMMAND_ARENA_DISBAND                          = 235,
    RBAC_PERM_COMMAND_ARENA_INFO                             = 236,
    RBAC_PERM_COMMAND_ARENA_LOOKUP                           = 237,
    RBAC_PERM_COMMAND_ARENA_RENAME                           = 238,
    RBAC_PERM_COMMAND_BAN                                    = 239,
    RBAC_PERM_COMMAND_BAN_ACCOUNT                            = 240,
    RBAC_PERM_COMMAND_BAN_CHARACTER                          = 241,
    RBAC_PERM_COMMAND_BAN_IP                                 = 242,
    RBAC_PERM_COMMAND_BAN_PLAYERACCOUNT                      = 243,
    RBAC_PERM_COMMAND_BANINFO                                = 244,
    RBAC_PERM_COMMAND_BANINFO_ACCOUNT                        = 245,
    RBAC_PERM_COMMAND_BANINFO_CHARACTER                      = 246,
    RBAC_PERM_COMMAND_BANINFO_IP                             = 247,
    RBAC_PERM_COMMAND_BANLIST                                = 248,
    RBAC_PERM_COMMAND_BANLIST_ACCOUNT                        = 249,
    RBAC_PERM_COMMAND_BANLIST_CHARACTER                      = 250,
    RBAC_PERM_COMMAND_BANLIST_IP                             = 251,
    RBAC_PERM_COMMAND_UNBAN                                  = 252,
    RBAC_PERM_COMMAND_UNBAN_ACCOUNT                          = 253,
    RBAC_PERM_COMMAND_UNBAN_CHARACTER                        = 254,
    RBAC_PERM_COMMAND_UNBAN_IP                               = 255,
    RBAC_PERM_COMMAND_UNBAN_PLAYERACCOUNT                    = 256,

    // custom permissions 1000+
    RBAC_PERM_MAX
};

enum RBACCommandResult
{
    RBAC_OK,
    RBAC_CANT_ADD_ALREADY_ADDED,
    RBAC_CANT_REVOKE_NOT_IN_LIST,
    RBAC_IN_GRANTED_LIST,
    RBAC_IN_DENIED_LIST,
    RBAC_ID_DOES_NOT_EXISTS
};

typedef std::bitset<RBAC_PERM_MAX> RBACPermissionContainer;
typedef std::set<uint32> RBACRoleContainer;
typedef std::set<uint32> RBACGroupContainer;

class RBACObject
{
    public:
        RBACObject(uint32 id = 0, std::string const& name = ""):
            _id(id), _name(name) { }

        virtual ~RBACObject() { }

        /// Gets the Name of the Object
        std::string const& GetName() const { return _name; }
        /// Gets the Id of the Object
        uint32 GetId() const { return _id; }

    private:
        uint32 _id;                                        ///> id of the object
        std::string _name;                                 ///> name of the object
};

/// Permission: Defines an autorization to perform certain operation
class RBACPermission: public RBACObject
{
    public:
        RBACPermission(uint32 id = 0, std::string const& name = ""):
            RBACObject(id, name) { }
};

/// Set of Permissions
class RBACRole: public RBACObject
{
    public:
        RBACRole(uint32 id = 0, std::string const& name = ""):
            RBACObject(id, name) { }

        /// Gets the Permissions assigned to this role
        RBACPermissionContainer const& GetPermissions() const { return _perms; }
        /// Grants a Permission (Adds)
        void GrantPermission(uint32 id);
        /// Revokes a Permission (Removes)
        void RevokePermission(uint32 id);

    private:
        RBACPermissionContainer _perms;                    ///> Set of permissions
};

/// Set of Roles
class RBACGroup: public RBACObject
{
    public:
        RBACGroup(uint32 id = 0, std::string const& name = ""):
            RBACObject(id, name) { }

        /// Gets the Roles assigned to this group
        RBACRoleContainer const& GetRoles() const { return _roles; }
        /// Grants a Role (Adds)
        void GrantRole(uint32 role);
        /// Revokes a Role (Removes)
        void RevokeRole(uint32 role);

    private:
        RBACRoleContainer _roles;                          ///> Set of Roles
};

/**
 * @name RBACData
 * @brief Contains all needed information about the acccount
 *
 * This class contains all the data needed to calculate the account permissions.
 * RBACDAta is formed by group permissions and user permissions through:
 * - Granted Groups, which contains roles, which contains permissions: Set of granted permissions
 * - Granted Roles, which contains permissions: Set of granted permissions
 * - Denied Roles, which contains permissions: Set of denied permissions
 * - Granted Permissions
 * - Denied Permissions
 *
 * Calculation of current Permissions: Granted permissions - Denied permissions
 * - Granted permissions: through groups, through roles and directly assigned
 * - Denied permissions: through roles and directly assigned
 */
class RBACData: public RBACObject
{
    public:
        RBACData(uint32 id, std::string const& name, int32 realmId):
            RBACObject(id, name), _realmId(realmId) { }

        /**
         * @name HasPermission
         * @brief Checks if certain action is allowed
         *
         * Checks if certain action can be performed.
         *
         * @return grant or deny action
         *
         * Example Usage:
         * @code
         * bool Player::CanJoinArena(Battleground* bg)
         * {
         *     return bg->isArena() && HasPermission(RBAC_PERM_JOIN_ARENA);
         * }
         * @endcode
         */
        bool HasPermission(uint32 permission) const { return _globalPerms.test(permission); }

        // Functions enabled to be used by command system
        /// Returns all the granted permissions (after computation)
        RBACPermissionContainer const& GetPermissions() const { return _globalPerms; }
        /// Returns all the granted permissions
        RBACPermissionContainer const& GetGrantedPermissions() const { return _grantedPerms; }
        /// Returns all the denied permissions
        RBACPermissionContainer const& GetDeniedPermissions() const { return _deniedPerms; }
        /// Returns all the granted roles
        RBACRoleContainer const& GetGrantedRoles() const { return _grantedRoles; }
        /// Returns all the denied roles
        RBACRoleContainer const& GetDeniedRoles() const { return _deniedRoles; }
        /// Returns all the granted groups
        RBACGroupContainer const& GetGroups() const { return _groups; }

        /**
         * @name AddGroup
         * @brief Adds new group
         *
         * Add a new group to the account. If realm is 0 or the group can not be added
         * No save to db action will be performed.
         *
         * Fails if group Id does not exists or group already present
         *
         * @param groupId group to be added
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to add the group
         *
         * Example Usage:
         * @code
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 groupId = 2;
         * if (rbac->AddGroup(groupId) == RBAC_OK)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Group %u succesfully added", groupId);
         * @endcode
         */
        RBACCommandResult AddGroup(uint32 groupId, int32 realmId = 0);

        /**
         * @name RemoveGroup
         * @brief Removes a group
         *
         * Removes a group from the account. If realm is 0 or the group can not be removed
         * No save to db action will be performed. Any delete operation will always affect
         * "all realms (-1)" in addition to the realm specified
         *
         * Fails if group not present
         *
         * @param groupId group to be removed
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to remove the group
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 groupId = 2;
         * if (rbac->RemoveGroup(groupId) == RBAC_OK)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Group %u succesfully removed", groupId);
         * @endcode
         */
        RBACCommandResult RemoveGroup(uint32 groupId, int32 realmId = 0);

        /**
         * @name GrantRole
         * @brief Grants a role
         *
         * Grants a role to the account. If realm is 0 or the role can not be added
         * No save to db action will be performed.
         *
         * Fails if role Id does not exists or role already granted or denied
         *
         * @param roleId role to be granted
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to grant the role
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 roleId = 2;
         * if (rbac->GrantRole(roleId) == RBAC_IN_DENIED_LIST)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Failed to grant role %u, already denied", roleId);
         * @endcode
         */
        RBACCommandResult GrantRole(uint32 roleId, int32 realmId = 0);

        /**
         * @name DenyRole
         * @brief Denies a role
         *
         * Denied a role to the account. If realm is 0 or the role can not be added
         * No save to db action will be performed.
         *
         * Fails if role Id does not exists or role already granted or denied
         *
         * @param roleId role to be denied
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to deny the role
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 roleId = 2;
         * if (rbac->DenyRole(roleId) == RBAC_ID_DOES_NOT_EXISTS)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Role Id %u does not exists", roleId);
         * @endcode
         */
        RBACCommandResult DenyRole(uint32 roleId, int32 realmId = 0);

        /**
         * @name RevokeRole
         * @brief Removes a role
         *
         * Removes a role from the account. If realm is 0 or the role can not be removed
         * No save to db action will be performed. Any delete operation will always affect
         * "all realms (-1)" in addition to the realm specified
         *
         * Fails if role not present
         *
         * @param roleId role to be removed
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to remove the role
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 roleId = 2;
         * if (rbac->RevokeRole(roleId) == RBAC_OK)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Role %u succesfully removed", roleId);
         * @endcode
         */
        RBACCommandResult RevokeRole(uint32 roleId, int32 realmId = 0);

        /**
         * @name GrantRole
         * @brief Grants a permission
         *
         * Grants a permission to the account. If realm is 0 or the permission can not be added
         * No save to db action will be performed.
         *
         * Fails if permission Id does not exists or permission already granted or denied
         *
         * @param permissionId permission to be granted
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to grant the permission
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 permissionId = 2;
         * if (rbac->GrantRole(permissionId) == RBAC_IN_DENIED_LIST)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Failed to grant permission %u, already denied", permissionId);
         * @endcode
         */
        RBACCommandResult GrantPermission(uint32 permissionId, int32 realmId = 0);

        /**
         * @name DenyPermission
         * @brief Denies a permission
         *
         * Denied a permission to the account. If realm is 0 or the permission can not be added
         * No save to db action will be performed.
         *
         * Fails if permission Id does not exists or permission already granted or denied
         *
         * @param permissionId permission to be denied
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to deny the permission
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 permissionId = 2;
         * if (rbac->DenyRole(permissionId) == RBAC_ID_DOES_NOT_EXISTS)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Role Id %u does not exists", permissionId);
         * @endcode
         */
        RBACCommandResult DenyPermission(uint32 permissionId, int32 realmId = 0);

        /**
         * @name RevokePermission
         * @brief Removes a permission
         *
         * Removes a permission from the account. If realm is 0 or the permission can not be removed
         * No save to db action will be performed. Any delete operation will always affect
         * "all realms (-1)" in addition to the realm specified
         *
         * Fails if permission not present
         *
         * @param permissionId permission to be removed
         * @param realmId realm affected
         *
         * @return Success or failure (with reason) to remove the permission
         *
         * Example Usage:
         * // previously defined "RBACData* rbac" with proper initialization
         * uint32 permissionId = 2;
         * if (rbac->RevokeRole(permissionId) == RBAC_OK)
         *     TC_LOG_DEBUG(LOG_FILTER_PLAYER, "Permission %u succesfully removed", permissionId);
         * @endcode
         */
        RBACCommandResult RevokePermission(uint32 permissionId, int32 realmId = 0);

        /// Loads all permissions, groups and roles assigned to current account
        void LoadFromDB();
    private:
        /// Saves a role to DB, Granted or Denied
        void SaveRole(uint32 role, bool granted, int32 realm);
        /// Saves a permission to DB, Granted or Denied
        void SavePermission(uint32 role, bool granted, int32 realm);

        /**
         * @name CalculateNewPermissions
         * @brief Calculates new permissions
         *
         * Calculates new permissions after some change in groups, roles or permissions.
         * The calculation is done Granted - Denied:
         * - Granted permissions: through groups, through roles and directly assigned
         * - Denied permissions: through roles and directly assigned
         */
        void CalculateNewPermissions();

        int32 GetRealmId() { return _realmId; }

        int32 _realmId;                                    ///> RealmId Affected
        RBACGroupContainer _groups;                        ///> Granted groups
        RBACRoleContainer _grantedRoles;                   ///> Granted roles
        RBACRoleContainer _deniedRoles;                    ///> Denied roles
        RBACPermissionContainer _grantedPerms;             ///> Granted permissions
        RBACPermissionContainer _deniedPerms;              ///> Denied permissions
        RBACPermissionContainer _globalPerms;              ///> Calculated permissions
};

#endif
