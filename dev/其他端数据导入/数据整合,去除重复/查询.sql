--删除重复id,站在同一个地方的生物
最容易理解的方法:

--原来一共770884条数据

select min(guid) from creature group by id,position_x, position_y, position_z;--找出id,位置重复的生物数据中guid最小的,即最后要保存的数据.
--656429条结果

select * from creature where guid not in(select min(guid)from creature group by id,position_x, position_y, position_z);--查询要删除的数据.
--114455条结果

select * from creature where guid not in(select min(guid)from creature group by id,position_x, position_y, position_z,map);
--113895条结果

select * from creature where guid not in(select min(guid)from creature group by id,position_x, position_y, position_z,map,zoneId);
--95717条结果

select * from creature where guid not in(select min(guid)from creature group by id,position_x, position_y, position_z,map,zoneId,areaId);
--74692条结果

select * from creature where guid not in(select min(guid)from creature group by 
id,map,zoneId,areaId,spawnDifficulties,phaseUseFlags,PhaseId,PhaseGroup,terrainSwapMap,modelid,equipment_id,position_x,position_y,
position_z,orientation,spawntimesecs,wander_distance,currentwaypoint,curhealth,curmana,MovementType,npcflag,unit_flags,unit_flags2,
unit_flags3,dynamicflags,ScriptName,StringId,VerifiedBuild,size);

--27132条结果


delete from creature where guid not in(select min_guid from(select min(guid) as min_guid from creature group by id,position_x, position_y, position_z)as x);

--版本1:删除114455条 暴风城NPC也有重复,但是重复的少点 例如暴风城贸易区的工会银行管理员 在此版本中就删除的很好.
--但有个大BUG,把节日NPC也删了,不能使用该版本.


delete from creature where guid not in(select min_guid from(select min(guid) as min_guid from creature group by id,position_x, position_y, position_z,map,zoneId,areaId)as x);
--版本2:删除74692条 暴风城NPC仍有重复.



delete from creature where guid not in(select min_guid from(select min(guid) as min_guid from creature group by  
id,map,zoneId,areaId,spawnDifficulties,phaseUseFlags,PhaseId,PhaseGroup,terrainSwapMap,modelid,equipment_id,position_x,position_y,
position_z,orientation,spawntimesecs,wander_distance,currentwaypoint,curhealth,curmana,MovementType,npcflag,unit_flags,unit_flags2,
unit_flags3,dynamicflags,ScriptName,StringId,VerifiedBuild,size)as x);
--版本3:27132条结果 暴风城NPC仍有重复.删除的数据保存在"D:\Program Files (x86)\WOWDIY\TrinityCore\通用\其他端数据导入\数据整合,去除重复\删除的数据.sql"
--目前使用删除本条查询后的数据

--注意先备份,此处套as是防止mysql报1903错误














--来源:https://blog.csdn.net/weixin_39820226/article/details/113553561,其中的方法二



--broadcast_text_locale
select min(ID) from broadcast_text_locale where locale='zhCN' group by ID,locale, Text_lang, Text1_lang;

--找出ID、两个文本重复的数据中ID最小的,即最后要保存的数据.
--197255 rows in set


select min(ID) from broadcast_text_locale where locale='zhCN' group by ID;
--195824 rows in set
--选择上一种


select * from broadcast_text_locale where ID not in(select min(ID) from broadcast_text_locale  group by ID,locale, Text_lang, Text1_lang);



select min(ID),locale, Text_lang, Text1_lang,VerifiedBuild from broadcast_text_locale where locale='zhCN' group by ID,locale, Text_lang, Text1_lang;
--查找locale为zhCN的不重复数据,只保留ID最小的
--197,255条数据

select *  from broadcast_text_locale where locale='zhCN';
--全部locale为zhCN的数据
--325,040条数据

delete from broadcast_text_locale where locale='zhCN';
--删除全部locale为zhCN的数据


--第2出对broadcast_text_locale表进行删减

select min(ID),locale, Text_lang, Text1_lang,VerifiedBuild from broadcast_text_locale where locale='zhCN' group by ID,locale;
--195824条数据(在手动删除一些重复数据后)


--删除重复数据(内容太多,未细看,为防止误删除,备份了数据,文件在同目录下,名称为:删除的zhCN中ID大于34632,VerifiedBuild为47936数据)
delete
FROM
broadcast_text_locale
WHERE
broadcast_text_locale.ID >=  '34631' AND
broadcast_text_locale.locale =  'zhcn' AND
broadcast_text_locale.VerifiedBuild =  '47936'

