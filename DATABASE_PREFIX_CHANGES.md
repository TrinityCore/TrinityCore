# Database Prefix Changes

## Summary

Updated all database configuration files to use `trinity_` prefix instead of default names to avoid conflicts with existing AzerothCore databases that use `acore_` prefix.

## Changes Made

### Files Modified

1. **`src/server/worldserver/worldserver.conf.dist`**
   - Changed default database names from:
     - `auth` → `trinity_auth`
     - `world` → `trinity_world`
     - `characters` → `trinity_characters`
     - `hotfixes` → `trinity_hotfixes`

2. **`src/server/bnetserver/bnetserver.conf.dist`**
   - Changed default database name from:
     - `auth` → `trinity_auth`

## Database Names

**TrinityCore will now use:**
- `trinity_auth` (Login/Auth database)
- `trinity_world` (World database)
- `trinity_characters` (Characters database)
- `trinity_hotfixes` (Hotfixes database)

**AzerothCore uses:**
- `acore_auth`
- `acore_world`
- `acore_characters`
- `acore_playerbots` (if using mod-playerbots)

## Next Steps

When setting up TrinityCore databases, use these names:

```sql
CREATE DATABASE trinity_auth CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
CREATE DATABASE trinity_world CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
CREATE DATABASE trinity_characters CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
CREATE DATABASE trinity_hotfixes CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
```

This ensures no conflicts with your existing AzerothCore setup.
