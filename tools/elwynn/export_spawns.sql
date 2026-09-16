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

    COALESCE(ca.path_id, 0) AS path_id,

    COALESCE(ge.event_entries, '') AS game_event_entries,
    COALESCE(ge.has_positive_event, 0) AS has_positive_event,
    COALESCE(ge.has_negative_event, 0) AS has_negative_event,

    CASE
        WHEN COALESCE(ge.has_positive_event, 0) = 1
         AND COALESCE(ge.has_negative_event, 0) = 1
            THEN 'REVIEW_EVENT'

        WHEN COALESCE(ge.has_positive_event, 0) = 1
            THEN 'EXCLUDED_EVENT'

        ELSE 'INCLUDED'
    END AS census_scope_status,

    COUNT(*) OVER (PARTITION BY c.id) AS template_spawn_count

FROM creature c

JOIN creature_template ct
    ON ct.entry = c.id

LEFT JOIN creature_addon ca
    ON ca.guid = c.guid

LEFT JOIN (
    SELECT
        guid,

        GROUP_CONCAT(
            eventEntry
            ORDER BY eventEntry
            SEPARATOR '|'
        ) AS event_entries,

        MAX(eventEntry > 0) AS has_positive_event,
        MAX(eventEntry < 0) AS has_negative_event

    FROM game_event_creature

    GROUP BY guid
) ge
    ON ge.guid = c.guid

WHERE c.zoneId = 12

ORDER BY c.guid;