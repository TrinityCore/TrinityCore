SELECT
    c.guid AS spawn_id,
    c.id AS entry,

    ct.name,
    ct.subname,

    c.map AS map_id,
    c.zoneId AS zone_id,
    c.areaId AS area_id,

    c.position_x,
    c.position_y,
    c.position_z,
    c.orientation,

    c.spawntimesecs,
    c.wander_distance,
    c.MovementType AS spawn_movement_type,

    c.npcflag AS spawn_npcflag,
    c.unit_flags AS spawn_unit_flags,
    c.dynamicflags AS spawn_dynamicflags,

    ct.minlevel,
    ct.maxlevel,
    ct.faction AS faction_template_id,
    ct.npcflag AS template_npcflag,
    ct.rank,
    ct.type AS creature_type,
    ct.family AS creature_family,
    ct.type_flags,
    ct.MovementType AS template_movement_type,
    ct.unit_flags AS template_unit_flags,
    ct.flags_extra,
    ct.AIName AS ai_name,
    ct.ScriptName AS script_name,

    ca.path_id,

    COUNT(*) OVER (PARTITION BY c.id) AS template_spawn_count

FROM creature c

JOIN creature_template ct
    ON ct.entry = c.id

LEFT JOIN creature_addon ca
    ON ca.guid = c.guid

WHERE c.zoneId = 12

ORDER BY c.guid;
