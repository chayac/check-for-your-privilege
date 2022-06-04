// https://observablehq.com/@d3/stacked-horizontal-bar-chart@550
import define1 from "./a33468b95d0b15b0@808.js";
import define2 from "./7a9e12f9fb3d8e06@459.js";

function _1(md){return(
md`# Stacked Bar Chart, Horizontal 

Population by age and state. Data: [American Community Survey](/@mbostock/working-with-the-census-api)`
)}

function _key(Legend,chart){return(
Legend(chart.scales.color, {title: "Age (years)"})
)}

function _chart(StackedBarChart,stateages,d3,ages,width){return(
StackedBarChart(stateages, {
  x: d => d.population / 1e6,
  y: d => d.state,
  z: d => d.age,
  xLabel: "Population (millions) →",
  yDomain: d3.groupSort(stateages, D => d3.sum(D, d => d.population), d => d.state), // sort y by x
  zDomain: ages,
  colors: d3.schemeSpectral[ages.length],
  width
})
)}

function _states(FileAttachment){return(
FileAttachment("us-population-state-age.csv").csv({typed: true})
)}

function _ages(states){return(
states.columns.slice(1)
)}

function _stateages(ages,states){return(
ages.flatMap(age => states.map(d => ({state: d.name, age, population: d[age]})))
)}

function _7(howto){return(
howto("StackedBarChart")
)}

function _8(altplot){return(
altplot(`Plot.plot({
  width,
  x: {axis: "top", tickFormat: "s"},
  color: {scheme: "spectral", domain: ages},
  marks: [
    Plot.barX(stateages, {
      y: "state",
      x: "population",
      fill: "age",
      sort: {y: "x", reverse: true}
    }),
    Plot.ruleX([0])
  ]
})`)
)}

function _StackedBarChart(d3){return(
function StackedBarChart(data, {
  x = d => d, // given d in data, returns the (quantitative) x-value
  y = (d, i) => i, // given d in data, returns the (ordinal) y-value
  z = () => 1, // given d in data, returns the (categorical) z-value
  title, // given d in data, returns the title text
  marginTop = 30, // top margin, in pixels
  marginRight = 0, // right margin, in pixels
  marginBottom = 0, // bottom margin, in pixels
  marginLeft = 40, // left margin, in pixels
  width = 640, // outer width, in pixels
  height, // outer height, in pixels
  xType = d3.scaleLinear, // type of x-scale
  xDomain, // [xmin, xmax]
  xRange = [marginLeft, width - marginRight], // [left, right]
  yDomain, // array of y-values
  yRange, // [bottom, top]
  yPadding = 0.1, // amount of y-range to reserve to separate bars
  zDomain, // array of z-values
  offset = d3.stackOffsetDiverging, // stack offset method
  order = d3.stackOrderNone, // stack order method
  xFormat, // a format specifier string for the x-axis
  xLabel, // a label for the x-axis
  colors = d3.schemeTableau10, // array of colors
} = {}) {
  // Compute values.
  const X = d3.map(data, x);
  const Y = d3.map(data, y);
  const Z = d3.map(data, z);

  // Compute default y- and z-domains, and unique them.
  if (yDomain === undefined) yDomain = Y;
  if (zDomain === undefined) zDomain = Z;
  yDomain = new d3.InternSet(yDomain);
  zDomain = new d3.InternSet(zDomain);

  // Omit any data not present in the y- and z-domains.
  const I = d3.range(X.length).filter(i => yDomain.has(Y[i]) && zDomain.has(Z[i]));

  // If the height is not specified, derive it from the y-domain.
  if (height === undefined) height = yDomain.size * 25 + marginTop + marginBottom;
  if (yRange === undefined) yRange = [height - marginBottom, marginTop];

  // Compute a nested array of series where each series is [[x1, x2], [x1, x2],
  // [x1, x2], …] representing the x-extent of each stacked rect. In addition,
  // each tuple has an i (index) property so that we can refer back to the
  // original data point (data[i]). This code assumes that there is only one
  // data point for a given unique y- and z-value.
  const series = d3.stack()
      .keys(zDomain)
      .value(([, I], z) => X[I.get(z)])
      .order(order)
      .offset(offset)
    (d3.rollup(I, ([i]) => i, i => Y[i], i => Z[i]))
    .map(s => s.map(d => Object.assign(d, {i: d.data[1].get(s.key)})));

  // Compute the default x-domain. Note: diverging stacks can be negative.
  if (xDomain === undefined) xDomain = d3.extent(series.flat(2));

  // Construct scales, axes, and formats.
  const xScale = xType(xDomain, xRange);
  const yScale = d3.scaleBand(yDomain, yRange).paddingInner(yPadding);
  const color = d3.scaleOrdinal(zDomain, colors);
  const xAxis = d3.axisTop(xScale).ticks(width / 80, xFormat);
  const yAxis = d3.axisLeft(yScale).tickSizeOuter(0);

  // Compute titles.
  if (title === undefined) {
    const formatValue = xScale.tickFormat(100, xFormat);
    title = i => `${Y[i]}\n${Z[i]}\n${formatValue(X[i])}`;
  } else {
    const O = d3.map(data, d => d);
    const T = title;
    title = i => T(O[i], i, data);
  }

  const svg = d3.create("svg")
      .attr("width", width)
      .attr("height", height)
      .attr("viewBox", [0, 0, width, height])
      .attr("style", "max-width: 100%; height: auto; height: intrinsic;");

  svg.append("g")
      .attr("transform", `translate(0,${marginTop})`)
      .call(xAxis)
      .call(g => g.select(".domain").remove())
      .call(g => g.selectAll(".tick line").clone()
          .attr("y2", height - marginTop - marginBottom)
          .attr("stroke-opacity", 0.1))
      .call(g => g.append("text")
          .attr("x", width - marginRight)
          .attr("y", -22)
          .attr("fill", "currentColor")
          .attr("text-anchor", "end")
          .text(xLabel));

  const bar = svg.append("g")
    .selectAll("g")
    .data(series)
    .join("g")
      .attr("fill", ([{i}]) => color(Z[i]))
    .selectAll("rect")
    .data(d => d)
    .join("rect")
      .attr("x", ([x1, x2]) => Math.min(xScale(x1), xScale(x2)))
      .attr("y", ({i}) => yScale(Y[i]))
      .attr("width", ([x1, x2]) => Math.abs(xScale(x1) - xScale(x2)))
      .attr("height", yScale.bandwidth());

  if (title) bar.append("title")
      .text(({i}) => title(i));

  svg.append("g")
      .attr("transform", `translate(${xScale(0)},0)`)
      .call(yAxis);

  return Object.assign(svg.node(), {scales: {color}});
}
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  function toString() { return this.url; }
  const fileAttachments = new Map([
    ["us-population-state-age.csv", {url: new URL("./files/cacf3b872e296fd3cf25b9b8762dc0c3aa1863857ecba3f23e8da269c584a4cea9db2b5d390b103c7b386586a1104ce33e17eee81b5cc04ee86929f1ee599bfe", import.meta.url), mimeType: null, toString}]
  ]);
  main.builtin("FileAttachment", runtime.fileAttachments(name => fileAttachments.get(name)));
  main.variable(observer()).define(["md"], _1);
  main.variable(observer("key")).define("key", ["Legend","chart"], _key);
  main.variable(observer("chart")).define("chart", ["StackedBarChart","stateages","d3","ages","width"], _chart);
  main.variable(observer("states")).define("states", ["FileAttachment"], _states);
  main.variable(observer("ages")).define("ages", ["states"], _ages);
  main.variable(observer("stateages")).define("stateages", ["ages","states"], _stateages);
  main.variable(observer()).define(["howto"], _7);
  main.variable(observer()).define(["altplot"], _8);
  main.variable(observer("StackedBarChart")).define("StackedBarChart", ["d3"], _StackedBarChart);
  const child1 = runtime.module(define1);
  main.import("Legend", child1);
  main.import("Swatches", child1);
  const child2 = runtime.module(define2);
  main.import("howto", child2);
  main.import("altplot", child2);
  return main;
}
