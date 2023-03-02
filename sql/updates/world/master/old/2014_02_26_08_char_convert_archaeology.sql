INSERT INTO character_archaeology_finds (guid, id, count, date) 
SELECT guid, projectId, count, FROM_UNIXTIME(timeCreated) FROM character_archprojecthistory;

INSERT INTO character_archaeology (guid, sites, counts, projects)
SELECT guid, '', '', GROUP_CONCAT(projectId separator ' ') FROM character_archproject GROUP BY guid;

DROP TABLE IF EXISTS character_archproject;
DROP TABLE IF EXISTS character_archprojecthistory;
DROP TABLE IF EXISTS character_archprojecthistory;