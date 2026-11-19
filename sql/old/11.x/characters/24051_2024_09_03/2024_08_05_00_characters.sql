DELETE
  ctc,
  cte,
  ca
FROM
  character_trait_config AS ctc
  LEFT JOIN (
    SELECT
      ctc2.guid AS guid,
      MIN(ctc2.traitConfigId) AS traitConfigId
    FROM
      character_trait_config ctc2
    WHERE
      ctc2.type = 3
    GROUP BY
      ctc2.guid,
      ctc2.traitSystemId
  ) AS minctc ON ctc.guid = minctc.guid AND ctc.traitConfigId = minctc.traitConfigId
  LEFT JOIN character_trait_entry AS cte ON ctc.guid = cte.guid AND ctc.traitConfigId = cte.traitConfigId
  LEFT JOIN character_action AS ca ON ctc.guid = ca.guid AND ctc.traitConfigId = ca.traitConfigId
WHERE
  ctc.type = 3 AND
  minctc.traitConfigId IS NULL;
