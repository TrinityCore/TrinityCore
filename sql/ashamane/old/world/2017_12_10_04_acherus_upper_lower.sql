DELETE FROM areatrigger WHERE guid IN (41, 42);
INSERT INTO areatrigger (guid, id, map_id, spawn_mask, position_x, position_y, position_z, Scriptname) VALUES
(41, 100002, 1220, 1, -1464.24, 1124.26, 271.08, "at_legion_portal_archerus_to_upper"),
(42, 100002, 1220, 1, -1460.38, 1130.55, 314.79, "at_legion_portal_archerus_to_lower");
