"use strict";

const $ = (id) => document.getElementById(id);
const canvas = $("map");
const ctx = canvas.getContext("2d");
const FACTIONS = {
  0: "NEUTRAL_UNAFFILIATED", 1: "STORMWIND_ALLIANCE", 2: "DEFIAS_BROTHERHOOD",
  3: "RIVERPAW_GNOLLS", 4: "ELWYNN_KOBOLDS", 5: "ELWYNN_MURLOCS", 6: "ELWYNN_WOLVES",
};
function factionLabel(value) { return FACTIONS[value] || String(value); }
const BOUNDS = { north: -8100, south: -10250, west: 900, east: -1750 };
const WORLD_CENTER = { x: -(BOUNDS.west + BOUNDS.east) / 2, y: -(BOUNDS.north + BOUNDS.south) / 2 };
const landmarks = [
  { name: "STORMWIND", x: -8900, y: 620 },
  { name: "NORTHSHIRE", x: -8900, y: -200 },
  { name: "GOLDSHIRE", x: -9450, y: 60 },
  { name: "STONEFIELD FARM", x: -9890, y: 340 },
  { name: "MACLURE VINEYARDS", x: -10000, y: 40 },
];

let snapshot = { agents: [], stale: true, configured: false, age_ms: null };
let visible = [];
let selectedId = null;
let zoom = 1;
let panX = 0;
let panY = 0;
let cssWidth = 0;
let cssHeight = 0;
let pointerDown = null;
let dragged = false;
let requestPending = false;
let lastSuccess = 0;

function scale() {
  return Math.min(cssWidth / (BOUNDS.west - BOUNDS.east), cssHeight / (BOUNDS.north - BOUNDS.south)) * 0.92 * zoom;
}

function project(position) {
  const s = scale();
  return {
    x: cssWidth / 2 + (-position.y - WORLD_CENTER.x) * s + panX,
    y: cssHeight / 2 + (-position.x - WORLD_CENTER.y) * s + panY,
  };
}

function resizeCanvas() {
  const rect = canvas.getBoundingClientRect();
  cssWidth = rect.width;
  cssHeight = rect.height;
  const dpr = window.devicePixelRatio || 1;
  canvas.width = Math.round(cssWidth * dpr);
  canvas.height = Math.round(cssHeight * dpr);
  ctx.setTransform(dpr, 0, 0, dpr, 0, 0);
  render();
}

function drawGrid() {
  ctx.lineWidth = 1;
  ctx.strokeStyle = "#e0ebd115";
  for (let x = -10250; x <= -8100; x += 250) {
    const a = project({ x, y: BOUNDS.west });
    const b = project({ x, y: BOUNDS.east });
    ctx.beginPath(); ctx.moveTo(a.x, a.y); ctx.lineTo(b.x, b.y); ctx.stroke();
  }
  for (let y = -1750; y <= 900; y += 250) {
    const a = project({ x: BOUNDS.north, y });
    const b = project({ x: BOUNDS.south, y });
    ctx.beginPath(); ctx.moveTo(a.x, a.y); ctx.lineTo(b.x, b.y); ctx.stroke();
  }
  ctx.strokeStyle = "#d4e8c556";
  const nw = project({ x: BOUNDS.north, y: BOUNDS.west });
  const se = project({ x: BOUNDS.south, y: BOUNDS.east });
  ctx.strokeRect(nw.x, nw.y, se.x - nw.x, se.y - nw.y);
}

function drawLandmarks() {
  for (const place of landmarks) {
    const p = project(place);
    if (p.x < -100 || p.x > cssWidth + 100 || p.y < -30 || p.y > cssHeight + 30) continue;
    ctx.fillStyle = "#f2dba3b0";
    ctx.font = "600 10px Segoe UI, sans-serif";
    ctx.textAlign = "center";
    ctx.fillText(place.name, p.x, p.y - 13);
    ctx.beginPath(); ctx.arc(p.x, p.y - 3, 2.2, 0, Math.PI * 2); ctx.fill();
  }
}

function pointColor(agent) {
  const type = agent.type.toUpperCase();
  if (agent.in_combat) return "#ed9375";
  if (type.includes("GUARD")) return "#91bbdb";
  if (type.includes("MERCHANT") || type.includes("TRAINER")) return "#efd191";
  if (type.includes("PREDATOR") || type.includes("COMBAT")) return "#e9a477";
  return "#a8dbc0";
}

function render() {
  if (!cssWidth || !cssHeight) return;
  ctx.clearRect(0, 0, cssWidth, cssHeight);
  drawGrid();
  for (const agent of visible) {
    const p = project(agent.position);
    if (p.x < -8 || p.x > cssWidth + 8 || p.y < -8 || p.y > cssHeight + 8) continue;
    const isLive = agent.position.source === "live";
    const selected = agent.agent_id === selectedId;
    ctx.beginPath();
    ctx.arc(p.x, p.y, selected ? 6.5 : isLive ? 3.2 : 2.8, 0, Math.PI * 2);
    ctx.fillStyle = isLive ? pointColor(agent) : "#163628";
    ctx.strokeStyle = selected ? "#fff0b9" : pointColor(agent);
    ctx.lineWidth = selected ? 2.2 : isLive ? 0.6 : 1.5;
    ctx.fill(); ctx.stroke();
  }
  drawLandmarks();
}

function uniqueOptions(id, values, allLabel, label = String) {
  const select = $(id);
  const old = select.value;
  const sorted = [...new Set(values.map(String))].sort((a, b) => a.localeCompare(b, "cs", { numeric: true }));
  select.replaceChildren(new Option(allLabel, ""), ...sorted.map(value => new Option(label(value), value)));
  select.value = sorted.includes(old) ? old : "";
}

function filterAgents() {
  const query = $("search").value.trim().toLocaleLowerCase("cs");
  const type = $("type-filter").value;
  const faction = $("faction-filter").value;
  visible = snapshot.agents.filter(agent =>
    agent.position.map_id === 0 &&
    (!query || (agent.name || "").toLocaleLowerCase("cs").includes(query) || String(agent.agent_id).includes(query)) &&
    (!type || agent.type === type) &&
    (!faction || String(agent.world_faction) === faction) &&
    (!$('live-filter').checked || agent.position.source === "live") &&
    (!$('combat-filter').checked || agent.in_combat === true) &&
    (!$('goal-filter').checked || Boolean(agent.goal)) &&
    (!$('hunger-filter').checked || agent.needs.hunger > 0.7)
  );
  $("visible-count").textContent = `${visible.length.toLocaleString("cs-CZ")} zobrazeno`;
  render();
}

function showStatus(error = false) {
  const age = snapshot.age_ms === null ? null : snapshot.age_ms + (performance.now() - lastSuccess);
  const stale = error || snapshot.stale || age === null || age >= 5000;
  const dot = $("status-dot");
  dot.className = `status-dot ${snapshot.agents.length ? stale ? "stale" : "live" : "waiting"}`;
  $("status-text").textContent = error ? "Spojení s viewerem přerušeno" : !snapshot.configured ? "Telemetrie není nakonfigurována" : !snapshot.received_at_ms ? "Čekám na telemetrii" : stale ? "Telemetrie je zastaralá" : "Live telemetrie";
  $("updated-text").textContent = age === null ? "" : `· před ${Math.max(0, Math.floor(age / 1000))} s`;
  $("map-empty").hidden = snapshot.agents.length > 0;
  $("map-empty").textContent = !snapshot.configured ? "Nastavte WORLD_VIEWER_TELEMETRY_TOKEN a zapněte export ve worldserveru." : "Čekám na první snímek worldserveru…";
}

function text(id, value) { $(id).textContent = value === null || value === undefined || value === "" ? "—" : String(value); }
function fixed(value, digits = 2) { return value === null || value === undefined ? "—" : Number(value).toFixed(digits); }

function showDetail() {
  const agent = snapshot.agents.find(item => item.agent_id === selectedId);
  $("detail-empty").hidden = Boolean(agent);
  $("detail-content").hidden = !agent;
  if (!agent) return;
  text("detail-type", agent.type);
  text("detail-name", agent.name || `Agent ${agent.agent_id}`);
  text("detail-source", agent.position.source === "live" ? "● Live Creature position" : agent.position.source === "spawn" ? "○ Background · spawn position (non-live)" : "○ Background · last known position (non-live)");
  text("detail-id", agent.agent_id);
  text("detail-spawn", agent.spawn_id);
  text("detail-entry", agent.entry);
  text("detail-faction", factionLabel(agent.world_faction));
  text("detail-control", agent.control_mode);
  text("detail-state", agent.world_state);
  text("detail-tier", agent.simulation_tier);
  text("detail-group", agent.group_id);
  text("detail-health", agent.health === null || agent.health === undefined ? "Zdraví —" : `Zdraví ${agent.health} / ${agent.max_health ?? "—"}`);
  text("detail-combat", agent.in_combat === null || agent.in_combat === undefined ? "Boj —" : agent.in_combat ? "⚔ V boji" : "Mimo boj");
  text("detail-position", `X ${fixed(agent.position.x)} · Y ${fixed(agent.position.y)} · Z ${fixed(agent.position.z)} · Map ${agent.position.map_id}`);
  text("detail-goal", agent.goal);
  text("detail-utility", fixed(agent.goal_utility));
  text("detail-action", agent.action);
  text("detail-routine", agent.routine_goal);
  const labels = [
    ["HealthPressure", "health_pressure"], ["Hunger", "hunger"], ["Fatigue", "fatigue"],
    ["SafetyPressure", "safety_pressure"], ["ResourcePressure", "resource_pressure"],
  ];
  $("needs").replaceChildren(...labels.map(([label, key]) => {
    const row = document.createElement("div"); row.className = `need-row ${agent.needs[key] > 0.7 ? "high" : ""}`;
    const name = document.createElement("span"); name.textContent = label;
    const track = document.createElement("div"); track.className = "need-track";
    const fill = document.createElement("div"); fill.className = "need-fill"; fill.style.width = `${agent.needs[key] * 100}%`; track.append(fill);
    const value = document.createElement("span"); value.className = "need-value"; value.textContent = fixed(agent.needs[key]);
    row.append(name, track, value); return row;
  }));
}

async function poll() {
  if (requestPending) return;
  requestPending = true;
  try {
    const response = await fetch("/api/state", { cache: "no-store" });
    if (!response.ok) throw new Error(`HTTP ${response.status}`);
    snapshot = await response.json();
    lastSuccess = performance.now();
    $("total-count").textContent = snapshot.agents.length.toLocaleString("cs-CZ");
    const live = snapshot.agents.filter(agent => agent.position.source === "live").length;
    $("live-count").textContent = live.toLocaleString("cs-CZ");
    $("background-count").textContent = (snapshot.agents.length - live).toLocaleString("cs-CZ");
    uniqueOptions("type-filter", snapshot.agents.map(agent => agent.type), "Všechny typy");
    uniqueOptions("faction-filter", snapshot.agents.map(agent => agent.world_faction), "Všechny frakce", factionLabel);
    $("capture-time").textContent = snapshot.received_at_ms ? `Přijato ${new Date(snapshot.received_at_ms).toLocaleTimeString("cs-CZ")}` : "Bez snímku";
    showStatus(); filterAgents(); showDetail();
  } catch (_) {
    showStatus(true);
  } finally {
    requestPending = false;
    setTimeout(poll, 1000);
  }
}

for (const id of ["search", "type-filter", "faction-filter", "live-filter", "combat-filter", "goal-filter", "hunger-filter"]) {
  $(id).addEventListener(id === "search" ? "input" : "change", filterAgents);
}
$("reset-filters").addEventListener("click", () => {
  $("search").value = ""; $("type-filter").value = ""; $("faction-filter").value = "";
  for (const id of ["live-filter", "combat-filter", "goal-filter", "hunger-filter"]) $(id).checked = false;
  filterAgents();
});
$("reset-view").addEventListener("click", () => { zoom = 1; panX = 0; panY = 0; render(); });

canvas.addEventListener("wheel", event => {
  event.preventDefault();
  const rect = canvas.getBoundingClientRect();
  const px = event.clientX - rect.left; const py = event.clientY - rect.top;
  const old = zoom; zoom = Math.max(1, Math.min(10, zoom * (event.deltaY < 0 ? 1.2 : 1 / 1.2)));
  const ratio = zoom / old;
  panX = px - cssWidth / 2 - (px - cssWidth / 2 - panX) * ratio;
  panY = py - cssHeight / 2 - (py - cssHeight / 2 - panY) * ratio;
  render();
}, { passive: false });
canvas.addEventListener("pointerdown", event => { pointerDown = { x: event.clientX, y: event.clientY, panX, panY }; dragged = false; canvas.setPointerCapture(event.pointerId); });
canvas.addEventListener("pointermove", event => {
  if (!pointerDown) return;
  const dx = event.clientX - pointerDown.x; const dy = event.clientY - pointerDown.y;
  if (Math.hypot(dx, dy) > 4) dragged = true;
  if (dragged) { panX = pointerDown.panX + dx; panY = pointerDown.panY + dy; render(); }
});
canvas.addEventListener("pointerup", event => {
  if (!pointerDown) return;
  pointerDown = null;
  if (dragged) return;
  const rect = canvas.getBoundingClientRect();
  const px = event.clientX - rect.left; const py = event.clientY - rect.top;
  let nearest = null; let distance = 11 * 11;
  for (const agent of visible) {
    const p = project(agent.position); const d = (p.x - px) ** 2 + (p.y - py) ** 2;
    if (d < distance) { nearest = agent; distance = d; }
  }
  selectedId = nearest ? nearest.agent_id : null;
  showDetail(); render();
});

new ResizeObserver(resizeCanvas).observe(canvas);
setInterval(() => showStatus(lastSuccess !== 0 && performance.now() - lastSuccess >= 5000), 1000);
poll();
