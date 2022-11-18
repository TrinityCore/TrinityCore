--
UPDATE trinity_string SET content_default = 'AIName: %s\r\nScriptName: %s\r\StringID: %s\r\StringID Index: %u' WHERE entry = 5031;

ALTER TABLE creature 
  ADD COLUMN StringId VARCHAR(64) DEFAULT NULL AFTER ScriptName;
  
ALTER TABLE creature_template
  ADD COLUMN StringId VARCHAR(64) DEFAULT NULL AFTER ScriptName;

