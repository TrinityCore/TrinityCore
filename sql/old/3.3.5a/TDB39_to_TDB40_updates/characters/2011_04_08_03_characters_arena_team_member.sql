ALTER TABLE `arena_team_member`
ADD COLUMN `personalRating` SMALLINT(5) NOT NULL DEFAULT '0' AFTER guid;

UPDATE arena_team_member
INNER JOIN character_arena_stats ON arena_team_member.guid = character_arena_stats.guid
INNER JOIN arena_team ON arena_team.arenaTeamId = arena_team_member.arenaTeamId AND (slot = 0 AND TYPE = 2 OR slot = 1 AND TYPE = 3 OR slot = 2 AND TYPE = 5)
SET arena_team_member.personalRating = character_arena_stats.personalRating;

ALTER TABLE `character_arena_stats`
DROP COLUMN `personalRating`;
