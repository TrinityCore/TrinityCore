--
-- Drop previous functions/views if any
DROP VIEW IF EXISTS `vw_conditions_with_labels`;

-- Create the view
CREATE SQL SECURITY INVOKER VIEW `vw_conditions_with_labels` AS
(SELECT (
        CASE
            WHEN `SourceTypeOrReferenceId` = 0 THEN 'CONDITION_SOURCE_TYPE_NONE'
            WHEN `SourceTypeOrReferenceId` = 1 THEN 'CONDITION_SOURCE_TYPE_CREATURE_LOOT_TEMPLATE'
            WHEN `SourceTypeOrReferenceId` = 2 THEN 'CONDITION_SOURCE_TYPE_DISENCHANT_LOOT_TEMPLATE'
            WHEN `SourceTypeOrReferenceId` = 3 THEN 'CONDITION_SOURCE_TYPE_FISHING_LOOT_TEMPLATE'
            WHEN `SourceTypeOrReferenceId` = 4 THEN 'CONDITION_SOURCE_TYPE_GAMEOBJECT_LOOT_TEMPLATE'
            WHEN `SourceTypeOrReferenceId` = 5 THEN 'CONDITION_SOURCE_TYPE_ITEM_LOOT_TEMPLATE'
            WHEN `SourceTypeOrReferenceId` = 6 THEN 'CONDITION_SOURCE_TYPE_MAIL_LOOT_TEMPLATE'
            WHEN `SourceTypeOrReferenceId` = 7 THEN 'CONDITION_SOURCE_TYPE_MILLING_LOOT_TEMPLATE'
            WHEN `SourceTypeOrReferenceId` = 8 THEN 'CONDITION_SOURCE_TYPE_PICKPOCKETING_LOOT_TEMPLATE'
            WHEN `SourceTypeOrReferenceId` = 9 THEN 'CONDITION_SOURCE_TYPE_PROSPECTING_LOOT_TEMPLATE'
            WHEN `SourceTypeOrReferenceId` = 10 THEN 'CONDITION_SOURCE_TYPE_REFERENCE_LOOT_TEMPLATE'
            WHEN `SourceTypeOrReferenceId` = 11 THEN 'CONDITION_SOURCE_TYPE_SKINNING_LOOT_TEMPLATE'
            WHEN `SourceTypeOrReferenceId` = 12 THEN 'CONDITION_SOURCE_TYPE_SPELL_LOOT_TEMPLATE'
            WHEN `SourceTypeOrReferenceId` = 13 THEN 'CONDITION_SOURCE_TYPE_SPELL_IMPLICIT_TARGET'
            WHEN `SourceTypeOrReferenceId` = 14 THEN 'CONDITION_SOURCE_TYPE_GOSSIP_MENU'
            WHEN `SourceTypeOrReferenceId` = 15 THEN 'CONDITION_SOURCE_TYPE_GOSSIP_MENU_OPTION'
            WHEN `SourceTypeOrReferenceId` = 16 THEN 'CONDITION_SOURCE_TYPE_CREATURE_TEMPLATE_VEHICLE'
            WHEN `SourceTypeOrReferenceId` = 17 THEN 'CONDITION_SOURCE_TYPE_SPELL'
            WHEN `SourceTypeOrReferenceId` = 18 THEN 'CONDITION_SOURCE_TYPE_SPELL_CLICK_EVENT'
            WHEN `SourceTypeOrReferenceId` = 19 THEN 'CONDITION_SOURCE_TYPE_QUEST_AVAILABLE'
            WHEN `SourceTypeOrReferenceId` = 21 THEN 'CONDITION_SOURCE_TYPE_VEHICLE_SPELL'
            WHEN `SourceTypeOrReferenceId` = 22 THEN 'CONDITION_SOURCE_TYPE_SMART_EVENT'
            WHEN `SourceTypeOrReferenceId` = 23 THEN 'CONDITION_SOURCE_TYPE_NPC_VENDOR'
            WHEN `SourceTypeOrReferenceId` = 24 THEN 'CONDITION_SOURCE_TYPE_SPELL_PROC'
            WHEN `SourceTypeOrReferenceId` = 25 THEN 'CONDITION_SOURCE_TYPE_TERRAIN_SWAP'
            WHEN `SourceTypeOrReferenceId` = 26 THEN 'CONDITION_SOURCE_TYPE_PHASE'
            WHEN `SourceTypeOrReferenceId` = 27 THEN 'CONDITION_SOURCE_TYPE_GRAVEYARD'
            ELSE `SourceTypeOrReferenceId`
        END
    ) AS `SourceTypeOrReferenceId`,
    `SourceGroup`,
    `SourceEntry`,
    `SourceId`,
    `ElseGroup`,
    (
        CASE
            WHEN `SourceTypeOrReferenceId` =  0 THEN 'CONDITION_NONE'
            WHEN `SourceTypeOrReferenceId` =  1 THEN 'CONDITION_AURA'
            WHEN `SourceTypeOrReferenceId` =  2 THEN 'CONDITION_ITEM'
            WHEN `SourceTypeOrReferenceId` =  3 THEN 'CONDITION_ITEM_EQUIPPED'
            WHEN `SourceTypeOrReferenceId` =  4 THEN 'CONDITION_ZONEID'
            WHEN `SourceTypeOrReferenceId` =  5 THEN 'CONDITION_REPUTATION_RANK'
            WHEN `SourceTypeOrReferenceId` =  6 THEN 'CONDITION_TEAM'
            WHEN `SourceTypeOrReferenceId` =  7 THEN 'CONDITION_SKILL'
            WHEN `SourceTypeOrReferenceId` =  8 THEN 'CONDITION_QUESTREWARDED'
            WHEN `SourceTypeOrReferenceId` =  9 THEN 'CONDITION_QUESTTAKEN'
            WHEN `SourceTypeOrReferenceId` = 10 THEN 'CONDITION_DRUNKENSTATE'
            WHEN `SourceTypeOrReferenceId` = 11 THEN 'CONDITION_WORLD_STATE'
            WHEN `SourceTypeOrReferenceId` = 12 THEN 'CONDITION_ACTIVE_EVENT'
            WHEN `SourceTypeOrReferenceId` = 13 THEN 'CONDITION_INSTANCE_INFO'
            WHEN `SourceTypeOrReferenceId` = 14 THEN 'CONDITION_QUEST_NONE'
            WHEN `SourceTypeOrReferenceId` = 15 THEN 'CONDITION_CLASS'
            WHEN `SourceTypeOrReferenceId` = 16 THEN 'CONDITION_RACE'
            WHEN `SourceTypeOrReferenceId` = 17 THEN 'CONDITION_ACHIEVEMENT'
            WHEN `SourceTypeOrReferenceId` = 18 THEN 'CONDITION_TITLE'
            WHEN `SourceTypeOrReferenceId` = 19 THEN 'CONDITION_SPAWNMASK'
            WHEN `SourceTypeOrReferenceId` = 20 THEN 'CONDITION_GENDER'
            WHEN `SourceTypeOrReferenceId` = 21 THEN 'CONDITION_UNIT_STATE'
            WHEN `SourceTypeOrReferenceId` = 22 THEN 'CONDITION_MAPID'
            WHEN `SourceTypeOrReferenceId` = 23 THEN 'CONDITION_AREAID'
            WHEN `SourceTypeOrReferenceId` = 24 THEN 'CONDITION_CREATURE_TYPE'
            WHEN `SourceTypeOrReferenceId` = 25 THEN 'CONDITION_SPELL'
            WHEN `SourceTypeOrReferenceId` = 26 THEN 'CONDITION_PHASEMASK'
            WHEN `SourceTypeOrReferenceId` = 27 THEN 'CONDITION_LEVEL'
            WHEN `SourceTypeOrReferenceId` = 28 THEN 'CONDITION_QUEST_COMPLETE'
            WHEN `SourceTypeOrReferenceId` = 29 THEN 'CONDITION_NEAR_CREATURE'
            WHEN `SourceTypeOrReferenceId` = 30 THEN 'CONDITION_NEAR_GAMEOBJECT'
            WHEN `SourceTypeOrReferenceId` = 31 THEN 'CONDITION_OBJECT_ENTRY_GUID'
            WHEN `SourceTypeOrReferenceId` = 32 THEN 'CONDITION_TYPE_MASK'
            WHEN `SourceTypeOrReferenceId` = 33 THEN 'CONDITION_RELATION_TO'
            WHEN `SourceTypeOrReferenceId` = 34 THEN 'CONDITION_REACTION_TO'
            WHEN `SourceTypeOrReferenceId` = 35 THEN 'CONDITION_DISTANCE_TO'
            WHEN `SourceTypeOrReferenceId` = 36 THEN 'CONDITION_ALIVE'
            WHEN `SourceTypeOrReferenceId` = 37 THEN 'CONDITION_HP_VAL'
            WHEN `SourceTypeOrReferenceId` = 38 THEN 'CONDITION_HP_PCT'
            WHEN `SourceTypeOrReferenceId` = 39 THEN 'CONDITION_REALM_ACHIEVEMENT'
            WHEN `SourceTypeOrReferenceId` = 40 THEN 'CONDITION_IN_WATER'
            WHEN `SourceTypeOrReferenceId` = 41 THEN 'CONDITION_TERRAIN_SWAP'
            WHEN `SourceTypeOrReferenceId` = 42 THEN 'CONDITION_STAND_STATE'
            WHEN `SourceTypeOrReferenceId` = 43 THEN 'CONDITION_DAILY_QUEST_DONE'
            WHEN `SourceTypeOrReferenceId` = 44 THEN 'CONDITION_CHARMED'
            WHEN `SourceTypeOrReferenceId` = 45 THEN 'CONDITION_PET_TYPE'
            WHEN `SourceTypeOrReferenceId` = 46 THEN 'CONDITION_TAXI'
            WHEN `SourceTypeOrReferenceId` = 47 THEN 'CONDITION_QUESTSTATE'
            WHEN `SourceTypeOrReferenceId` = 48 THEN 'CONDITION_QUEST_OBJECTIVE_PROGRESS'
            WHEN `SourceTypeOrReferenceId` = 49 THEN 'CONDITION_DIFFICULTY_ID'
            WHEN `SourceTypeOrReferenceId` = 50 THEN 'CONDITION_GAMEMASTER'
            WHEN `SourceTypeOrReferenceId` = 51 THEN 'CONDITION_OBJECT_ENTRY_GUID_MASTER'
            WHEN `SourceTypeOrReferenceId` = 52 THEN 'CONDITION_TYPE_MASK_MASTER'
            ELSE `ConditionTypeOrReference`
        END
    ) AS `ConditionTypeOrReference`,
    `ConditionTarget`,
    `ConditionValue1`,
    `ConditionValue2`,
    `ConditionValue3`,
    `NegativeCondition`,
    `ErrorType`,
    `ErrorTextId`,
    `ScriptName`,
    `Comment`
 FROM conditions);
