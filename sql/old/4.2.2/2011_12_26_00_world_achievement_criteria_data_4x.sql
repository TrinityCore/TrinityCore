-- Remove unneeded achievement criteria datas for implemented DBC conditions:
-- TYPE_T_PLAYER_DEAD 4, TYPE_S_AREA 6, TYPE_MAP_DIFFICULTY 12, TYPE_MAP_ID 20
DELETE FROM achievement_criteria_data WHERE `type` IN (4, 6, 12, 20);
