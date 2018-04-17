SET @PHASE_169      = 172329;
SET @ZONE_ACHERUS   = 4298;
SET @TEAM_BOTH      = -1;

DELETE FROM spell_area WHERE spell IN (@PHASE_169) AND AREA IN (@ZONE_ACHERUS);
INSERT INTO spell_area (spell, AREA, quest_start, quest_end, teamid, flags, quest_start_status, quest_end_status) VALUES
(@PHASE_169, @ZONE_ACHERUS, 0, 0, @TEAM_BOTH, 3, 0, 0);
