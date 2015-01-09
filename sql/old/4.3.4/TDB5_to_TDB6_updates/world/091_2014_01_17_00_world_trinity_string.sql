DELETE FROM trinity_string where entry in (11002, 11003, 11004, 11005, 11006, 11007);
INSERT INTO `trinity_string` VALUES
('11002', 'Server: %s has kicked %s, reason: %s', '', '', '', '', '', '', '', ''),
('11003', 'Server: %s has muted %s for %u minutes, reason: %s', '', '', '', '', '', '', '', ''),
('11004', 'Server: %s has banned character %s for %s, reason: %s', '', '', '', '', '', '', '', ''),
('11005', 'Server: %s has banned character %s permanetly, reason: %s', '', '', '', '', '', '', '', ''),
('11006', 'Server: %s has banned %s for %s, reason: %s', '', '', '', '', '', '', '', ''),
('11007', 'Server: %s has banned %s permanetly, reason: %s', '', '', '', '', '', '', '', '');
