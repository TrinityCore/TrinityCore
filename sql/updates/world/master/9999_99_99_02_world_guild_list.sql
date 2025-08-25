
-- Strings for .guild list output
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
-- Title
(1219, "|cff00ff00=== Guild list ===|r"),
-- Header (6 string args for labels)
(1220, "%6s | %-24s | %-16s | %-19s | %7s | %10s"),
-- Row (id, name, gm, created, members, bankGold)
(1221, "|cffffff00%6u|r | %-24.24s | %-16.16s | %-19s | %7u | %10u"),
-- Total
(1222, "|cff00ff00Total guilds: %zu|r"),
-- Column labels
(1223, "ID"),
(1224, "Name"),
(1225, "GM"),
(1226, "Created"),
(1227, "Members"),
(1228, "Bank (g)")
ON DUPLICATE KEY UPDATE `content_default` = VALUES(`content_default`);
