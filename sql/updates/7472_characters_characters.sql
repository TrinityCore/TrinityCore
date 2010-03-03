ALTER TABLE characters
  ADD COLUMN `arenaPoints` int(10) UNSIGNED NOT NULL default '0' AFTER arena_pending_points,
  ADD COLUMN `totalHonorPoints` int(10) UNSIGNED NOT NULL default '0' AFTER arenaPoints,
  ADD COLUMN `todayHonorPoints` int(10) UNSIGNED NOT NULL default '0' AFTER totalHonorPoints,
  ADD COLUMN `yesterdayHonorPoints` int(10) UNSIGNED NOT NULL default '0' AFTER todayHonorPoints,
  ADD COLUMN `totalKills` int(10) UNSIGNED NOT NULL default '0' AFTER yesterdayHonorPoints,
  ADD COLUMN `todayKills` smallint(5) UNSIGNED NOT NULL default '0' AFTER totalKills,
  ADD COLUMN `yesterdayKills` smallint(5) UNSIGNED NOT NULL default '0' AFTER todayKills,
  ADD COLUMN `chosenTitle` int(10) UNSIGNED NOT NULL default '0' AFTER yesterdayKills,
  ADD COLUMN `knownCurrencies` bigint(20) UNSIGNED NOT NULL default '0' AFTER chosenTitle,
  ADD COLUMN `watchedFaction` int(10) NOT NULL default '0' AFTER knownCurrencies,
  ADD COLUMN `drunk` smallint(5) UNSIGNED NOT NULL default '0' AFTER watchedFaction,
  ADD COLUMN `health` int(10) UNSIGNED NOT NULL default '0' AFTER drunk,
  ADD COLUMN `power1` int(10) UNSIGNED NOT NULL default '0' AFTER health,
  ADD COLUMN `power2` int(10) UNSIGNED NOT NULL default '0' AFTER power1,
  ADD COLUMN `power3` int(10) UNSIGNED NOT NULL default '0' AFTER power2,
  ADD COLUMN `power4` int(10) UNSIGNED NOT NULL default '0' AFTER power3,
  ADD COLUMN `power5` int(10) UNSIGNED NOT NULL default '0' AFTER power4,
  ADD COLUMN `power6` int(10) UNSIGNED NOT NULL default '0' AFTER power5,
  ADD COLUMN `power7` int(10) UNSIGNED NOT NULL default '0' AFTER power6;

UPDATE characters SET
  arenaPoints = arena_pending_points +
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1278))+2, length(SUBSTRING_INDEX(data, ' ', 1278+1))- length(SUBSTRING_INDEX(data, ' ', 1278)) - 1),
  totalHonorPoints =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1277))+2, length(SUBSTRING_INDEX(data, ' ', 1277+1))- length(SUBSTRING_INDEX(data, ' ', 1277)) - 1),
  todayHonorPoints =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1226))+2, length(SUBSTRING_INDEX(data, ' ', 1226+1))- length(SUBSTRING_INDEX(data, ' ', 1226)) - 1),
  yesterdayHonorPoints =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1227))+2, length(SUBSTRING_INDEX(data, ' ', 1227+1))- length(SUBSTRING_INDEX(data, ' ', 1227)) - 1),
  totalKills =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1228))+2, length(SUBSTRING_INDEX(data, ' ', 1228+1))- length(SUBSTRING_INDEX(data, ' ', 1228)) - 1),
  todayKills =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1225))+2, length(SUBSTRING_INDEX(data, ' ', 1225+1))- length(SUBSTRING_INDEX(data, ' ', 1225)) - 1) & 0x0000FFFF,
  yesterdayKills =
    (SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1225))+2, length(SUBSTRING_INDEX(data, ' ', 1225+1))- length(SUBSTRING_INDEX(data, ' ', 1225)) - 1) & 0xFFFF0000) >> 16,
  chosenTitle =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ',  321))+2, length(SUBSTRING_INDEX(data, ' ',  321+1))- length(SUBSTRING_INDEX(data, ' ',  321)) - 1),
  knownCurrencies =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ',  632))+2, length(SUBSTRING_INDEX(data, ' ',  632+1))- length(SUBSTRING_INDEX(data, ' ',  632)) - 1),
  watchedFaction =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ', 1230))+2, length(SUBSTRING_INDEX(data, ' ', 1230+1))- length(SUBSTRING_INDEX(data, ' ', 1230)) - 1),
  drunk =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ',  155))+2, length(SUBSTRING_INDEX(data, ' ',  155+1))- length(SUBSTRING_INDEX(data, ' ',  155)) - 1) & 0xFFFE,
  health =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ',   23))+2, length(SUBSTRING_INDEX(data, ' ',   23+1))- length(SUBSTRING_INDEX(data, ' ',   23)) - 1),
  power1 =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ',   24))+2, length(SUBSTRING_INDEX(data, ' ',   24+1))- length(SUBSTRING_INDEX(data, ' ',   24)) - 1),
  power2 =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ',   25))+2, length(SUBSTRING_INDEX(data, ' ',   25+1))- length(SUBSTRING_INDEX(data, ' ',   25)) - 1),
  power3 =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ',   26))+2, length(SUBSTRING_INDEX(data, ' ',   26+1))- length(SUBSTRING_INDEX(data, ' ',   26)) - 1),
  power4 =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ',   27))+2, length(SUBSTRING_INDEX(data, ' ',   27+1))- length(SUBSTRING_INDEX(data, ' ',   27)) - 1),
  power5 =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ',   28))+2, length(SUBSTRING_INDEX(data, ' ',   28+1))- length(SUBSTRING_INDEX(data, ' ',   28)) - 1),
  power6 =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ',   29))+2, length(SUBSTRING_INDEX(data, ' ',   29+1))- length(SUBSTRING_INDEX(data, ' ',   29)) - 1),
  power7 =
    SUBSTRING(data, length(SUBSTRING_INDEX(data, ' ',   30))+2, length(SUBSTRING_INDEX(data, ' ',   30+1))- length(SUBSTRING_INDEX(data, ' ',   30)) - 1);

ALTER TABLE characters
  DROP COLUMN arena_pending_points;