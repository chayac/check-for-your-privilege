// https://observablehq.com/@chaya/check-for-your-privilege@1457
import define1 from "./743260d2bcf09524@495.js";
import define2 from "./3ea120aea44569d7@550.js";

function _1(md){return(
md`# Check for Your Privilege
###### An Interactive Tool to Explore Income Disparities and How to Fix Them`
)}

function _checkboxes(Inputs){return(
Inputs.checkbox(["GET", "READY", "TO", "CHECK", "ALL", "THE", "BOXES"],)
)}

function _3(equity_map,md){return(
md`<p style="text-align: center; padding-bottom: 5px; padding-right: 15px; float: right; display: block;"><img src=${equity_map.src} width="200" height="200"  /><br /><span style="font-size: small;"><a href="https://data-seattlecitygis.opendata.arcgis.com/datasets/SeattleCityGIS::racial-and-social-equity-composite-index/about">Racial and Social Equity Composite Index</a></span></p>

As a software engineer and long-time Seattle resident, I know that Big Tech has impacted Seattle (and other cities) in a myriad of ways: good and bad, large and small, everywhere in between, but all very real. In [*The Gentrification of the Internet*](https://www.ucpress.edu/book/9780520344907/the-gentrification-of-the-internet), the author notes that Northern California, "Northern California's big cities are getting ***more unequal and less diverse***," resulting from urban gentrification in the areas surround tech companies and a tech workforce that is "***disproportionately White, male, and young***". While gentrification has both positive and negative impacts, "benefits aren't even distributed. Urban gentrification tends to make rich people richer and poor people poorer."


For my [CS109 Probability Challenge](http://web.stanford.edu/class/cs109/handouts/challenge.html), I built this interactive tool to explore disparities associated with Big Tech. Using conditional probability, you can ***check your privilege*** by comparing the odds of being high or low income for tech and non-tech workers, and then ***write a check for your privilege*** to organizations working to make Seattle better for everyone.`
)}

function _4(md){return(
md`## Explore Income Distributions

Do different people have different probabilities of having high or low income? We can use a frequentist definition of probability to estimate these probabilities by counting the number of people in each group. These charts show the distribution of these counts between two different groups having factors associated with the typical tech worker.

***Use the checkboxes below to select different factors*** and compare the distributions between the two charts.`
)}

function _sizes(Inputs,factor_options){return(
Inputs.checkbox(factor_options, {value: ["tech"], label: "Factors"})
)}

function _6(labels,md){return(
md`Distribution for: ${labels}`
)}

function _chart5(BarChart,data,group_n,d3,width){return(
BarChart(data, {
  x: d => d.value,
  y: d => d.name,
  // yDomain: d3.groupSort(
  //   data,
  //   // (D) => D[0].value / group_n, // proportion of first age group
  //   // d => d.sort_order,
  //   d => d.name,
  //   d => d.sort_order // sort y by x
  // ),
  xDomain: [0, group_n],
  // yDomain: d3.map(d3.sort(data, (a, b) => d3.descending(a.sort_order, b.sort_order)), d => d.name),
  yDomain: d3.map(d3.sort(data, d => d.sort_order), d => d.name),
  // xFormat: "%",
  xLabel: "Number of People →",
  width,
  color: "steelblue",
  marginLeft: 100,
})
)}

function _8(cf_labels,md){return(
md`Compared to: ${cf_labels}`
)}

function _chart6(BarChart,cf_data,cf_group_n,d3,data,width){return(
BarChart(cf_data, {
  x: d => d.value,
  y: d => d.name,
  // yDomain: d3.groupSort(
  //   data,
  //   // (D) => D[0].value / group_n, // proportion of first age group
  //   // d => d.sort_order,
  //   d => d.name,
  //   d => d.sort_order // sort y by x
  // ),
  xDomain: [0, cf_group_n],
  // yDomain: d3.map(d3.sort(data, (a, b) => d3.descending(a.sort_order, b.sort_order)), d => d.name),
  yDomain: d3.map(d3.sort(data, d => d.sort_order), d => d.name),
  // xFormat: "%",
  xLabel: "Number of People →",
  width,
  color: "lightgreen",
  marginLeft: 100,
})
)}

function _10(md){return(
md`Intuitively, distribution is more likely to be equitable if both charts have similar shapes for demographics that should be **independent of income**. If you have a bachelor's degree in a STEM field, your income distribution should be the same regardless of race and gender (but might reasonably differ from someone without a degree).

How do we translate this intuitive sense into something we can quantify?`
)}

function _11(md){return(
md`## Fairness through Awareness`
)}

function _12(tex,md){return(
md`How do we know what is equitable? We can borrow a formal definition of fairness from AI: **fairness through awareness**. Fairness through awareness uses knowledge of demographic factors to determine if an outcome is fairly distributed across demographics. In terms of probability, we can use **conditional probability** to measure these differences.

Under the parity definition of fairness, an outcome is fairly distributed if the conditional probability of an outcome for someone with a given demographic factor is the same as the conditional probability of the same outcome for someone with a given demographic factor. For example:

${tex`P(\text{High Income | White}) = P(\text{High Income | Non-White})`}`
)}

function _13(md){return(
md`To see this in action, ***use the checkboxes*** to see how the odds of being high or low income change based on the factors you select. (You can also use the checkboxes above, and changing either will update both sections.)`
)}

function _14(Inputs,factor_options,$0){return(
Inputs.bind(Inputs.checkbox(factor_options, {value: ["tech"], label: "Factors"}), $0)
)}

function _15(round4,p_high_income,labels,calcPHighIncome,data,cf_labels,cf_data,p_low_income,calcPLowIncome,md){return(
md`Odds of High Income:
* Across all samples: ${round4(p_high_income/(1-p_high_income))}
* For ${labels}: ${round4(calcPHighIncome(data))} (ratio to base: ${round4(calcPHighIncome(data)/(p_high_income/(1-p_high_income)))})
* For ${cf_labels}: ${round4(calcPHighIncome(cf_data))} (ratio to base: ${round4(calcPHighIncome(cf_data)/(p_high_income/(1-p_high_income)))})

Odds of Low Income:
* Across all samples: ${round4(p_low_income/(1-p_low_income))}
* For ${labels}: ${round4(calcPLowIncome(data))} (ratio to base: ${round4(calcPLowIncome(data)/(p_low_income/(1-p_low_income)))})
* For ${cf_labels}: ${round4(calcPLowIncome(cf_data))} (ratio to base: ${round4(calcPLowIncome(cf_data)/(p_low_income/(1-p_low_income)))})`
)}

function _16(md){return(
md`Parity is achieved when **conditional odds are similar to each other**, meaning the effect on the outcome is similar for both groups.

We can also use ratio of the conditional odds to the unconditional odds: if both groups have ratios greater than 1, then both sets of factors have a positive impact on the outcome (and vice versa if less than 1). 

If the magnitudes of the ratios are similar, then there might be parity here. **But if the magnitudes are very different or go in opposite directions, then there is likely a disparity between the groups**.

Try a few different combinations, and I think you will agree: **parity is not being satisfied here**.`
)}

function _17(tex,md){return(
md`## Digging Deeper with Bayes' Theorem

So, by comparing the conditional probabilities for different groups, we have seen that disparities exist. How do we better understand that?

We can use **Bayes' Theorem** to decompose the conditional probabilities and get insight into where these differences arise. 

${tex`P(H|F) = \dfrac{P(F | H) P(H)}{P(F)}`}

For example, the probability of having high income for a group P(H|F) is a combination of: 
* P(F): the probability of being in that group
* P(H): the probability of having high income
* P(F|H): the probability of being in that group for someone with high income

The next two sections show how Bayes' theorem is used to calculate the conditional probabilities for the groups selected. **Click those checkboxes!**`
)}

function _18(Inputs,factor_options,$0){return(
Inputs.bind(Inputs.checkbox(factor_options, {value: ["tech"], label: "Factors"}), $0)
)}

function _19(round4,p_high_income,md){return(
md`## Odds of High Income

Base Odds: ${round4(p_high_income/(1-p_high_income))}`
)}

function _20(labels,data,n_high_income,cf_data,n,p_high_income,round4,calcPHighIncome,cf_labels,htl){return(
htl.html`<table class="table">
  <thead>
    <tr>
<!--       <th scope="col">#</th> -->
      <th scope="col">Calculation</th>
      <th scope="col"> </th>
      <th scope="col">Selected</th>
      <th scope="col">Comparison</th>
    </tr>
  </thead>
  <tbody>
    
    <tr class="table-danger">
      <td colspan=2>P(${labels} | High Income)</td>
      <td>${Math.round(10000 * (data.filter(d => d.name == "High Income")[0]["value"])/n_high_income)/10000}</td>
      <td>${Math.round(10000 * (cf_data.filter(d => d.name == "High Income")[0]["value"])/n_high_income)/10000}</td>
    </tr>
    <tr>
      <td> </td>
      <td># High Income and ${labels}</td>
      <td>${data.filter(d => d.name == "High Income")[0]["value"]}</td>
      <td>${cf_data.filter(d => d.name == "High Income")[0]["value"]}</td>
    </tr>
    <tr>
      <td> </td>
      <td># High Income</td>
      <td>${n_high_income}</td>
      <td>${n_high_income}</td>
    </tr>
    
    <tr class="table-success">
      <td colspan=2>P(${labels} | Not High Income)</td>
      <td>${Math.round(10000 * (data.filter(d => d.name == "Not High Income")[0]["value"])/(n - n_high_income))/10000}</td>
      <td>${Math.round(10000 * (cf_data.filter(d => d.name == "Not High Income")[0]["value"])/(n - n_high_income))/10000}</td>
    </tr>
    <tr>
      <td> </td>
      <td># Not High Income and ${labels}</td>
      <td>${data.filter(d => d.name == "Not High Income")[0]["value"]}</td>
      <td>${cf_data.filter(d => d.name == "Not High Income")[0]["value"]}</td>
    </tr>
    <tr>
      <td> </td>
      <td># Not High Income</td>
      <td>${(n - n_high_income)}</td>
      <td>${(n - n_high_income)}</td>
    </tr>

    <tr class="table-info">
      <td colspan=2>P(High Income)</td>
      <td>${Math.round(10000 * p_high_income) / 10000}</td>
      <td>${Math.round(10000 * p_high_income) / 10000}</td>
    </tr>
    <tr>
      <td> </td>
      <td># High Income</td>
      <td>${n_high_income}</td>
      <td>${n_high_income}</td>
    </tr>
    <tr>
      <td> </td>
      <td>Total N</td>
      <td>${n}</td>
      <td>${n}</td>
    </tr>

  </tbody>
  <tfoot>
    <tr>
      <td colspan=2>P(High Income | ${labels})</td>
      <td>${
        round4(calcPHighIncome(data))
      }</td>
      <td>${
        round4(calcPHighIncome(cf_data))
      }</td>
    </tr>
    <tr>
      <td colspan=2>Odds(High Income | ${labels})</td>
      <td>${round4((calcPHighIncome(data))/(1-calcPHighIncome(data)))
      }</td>
      <td>${
        round4((calcPHighIncome(cf_data))/(1-calcPHighIncome(cf_data)))
      }</td>
    </tr>
    <tr>
      <td colspan=2>Ratio of Odds(High Income | ${labels}) to Base Odds(High Income)</td>
      <td>${round4(
        ((calcPHighIncome(data))/(1-calcPHighIncome(data)))/
        (p_high_income/(1-p_high_income))
        )
      }</td>
      <td>${
        round4(
        ((calcPHighIncome(cf_data))/(1-calcPHighIncome(cf_data)))/
        (p_high_income/(1-p_high_income))
        )
      }</td>
    </tr>

    <tr>
      <td colspan=2>Ratio of Odds(High Income | ${labels}) to Odds(High Income | ${cf_labels})</td>
      <td colspan=2>${round4(
        ((calcPHighIncome(data))/(1-calcPHighIncome(data)))/
        ((calcPHighIncome(cf_data))/(1-calcPHighIncome(cf_data)))
        )
      }</td>
    </tr>
  </tfoot>
  
</table>`
)}

function _21(round4,p_low_income,md){return(
md`## Odds for Low Income

Base odds: ${round4(p_low_income/(1-p_low_income))}`
)}

function _22(labels,data,n_low_income,cf_data,n,p_low_income,round4,calcPLowIncome,cf_labels,htl){return(
htl.html`<table class="table">
  <thead>
    <tr>
<!--       <th scope="col">#</th> -->
      <th scope="col">Calculation</th>
      <th scope="col"> </th>
      <th scope="col">Selected</th>
      <th scope="col">Comparison</th>
    </tr>
  </thead>
  <tbody>
    
    <tr class="table-danger">
      <td colspan=2>P(${labels} | Low Income)</td>
      <td>${Math.round(10000 * (data.filter(d => d.name == "Low Income")[0]["value"])/n_low_income)/10000}</td>
      <td>${Math.round(10000 * (cf_data.filter(d => d.name == "Low Income")[0]["value"])/n_low_income)/10000}</td>
    </tr>
    <tr>
      <td> </td>
      <td># Low Income and ${labels}</td>
      <td>${data.filter(d => d.name == "Low Income")[0]["value"]}</td>
      <td>${cf_data.filter(d => d.name == "Low Income")[0]["value"]}</td>
    </tr>
    <tr>
      <td> </td>
      <td># Low Income</td>
      <td>${n_low_income}</td>
      <td>${n_low_income}</td>
    </tr>
    
    <tr class="table-success">
      <td colspan=2>P(${labels} | Not Low Income)</td>
      <td>${Math.round(10000 * (data.filter(d => d.name == "Not Low Income")[0]["value"])/(n - n_low_income))/10000}</td>
      <td>${Math.round(10000 * (cf_data.filter(d => d.name == "Not Low Income")[0]["value"])/(n - n_low_income))/10000}</td>
    </tr>
    <tr>
      <td> </td>
      <td># Not Low Income and ${labels}</td>
      <td>${data.filter(d => d.name == "Not Low Income")[0]["value"]}</td>
      <td>${cf_data.filter(d => d.name == "Not Low Income")[0]["value"]}</td>
    </tr>
    <tr>
      <td> </td>
      <td># Not Low Income</td>
      <td>${(n - n_low_income)}</td>
      <td>${(n - n_low_income)}</td>
    </tr>

    <tr class="table-info">
      <td colspan=2>P(Low Income)</td>
      <td>${Math.round(10000 * p_low_income) / 10000}</td>
      <td>${Math.round(10000 * p_low_income) / 10000}</td>
    </tr>
    <tr>
      <td> </td>
      <td># Low Income</td>
      <td>${n_low_income}</td>
      <td>${n_low_income}</td>
    </tr>
    <tr>
      <td> </td>
      <td>Total N</td>
      <td>${n}</td>
      <td>${n}</td>
    </tr>

  </tbody>
  <tfoot>
    <tr>
      <td colspan=2>P(Low Income | ${labels})</td>
      <td>${
        round4(calcPLowIncome(data))
      }</td>
      <td>${
        round4(calcPLowIncome(cf_data))
      }</td>
    </tr>
    <tr>
      <td colspan=2>Odds(Low Income | ${labels})</td>
      <td>${round4((calcPLowIncome(data))/(1-calcPLowIncome(data)))
      }</td>
      <td>${
        round4((calcPLowIncome(cf_data))/(calcPLowIncome(cf_data)))
      }</td>
    </tr>
    <tr>
      <td colspan=2>Ratio of Odds(Low Income | ${labels}) to Base Odds(Low Income)</td>
      <td>${round4(
        ((calcPLowIncome(data))/(calcPLowIncome(data)))/
        (p_low_income/(1-p_low_income))
        )
      }</td>
      <td>${
        round4(
        ((calcPLowIncome(cf_data))/(calcPLowIncome(cf_data)))/
        (p_low_income/(1-p_low_income))
        )
      }</td>
    </tr>

    <tr>
      <td colspan=2>Ratio of Odds(Low Income | ${labels}) to Odds(Low Income | ${cf_labels})</td>
      <td colspan=2>${round4(
        ((calcPLowIncome(data))/(calcPLowIncome(data)))/
        ((calcPLowIncome(cf_data))/(calcPLowIncome(cf_data)))
        )
      }</td>
    </tr>
  </tfoot>
  
</table>`
)}

function _23(tex,md){return(
md`## Using Bayes' Theorem for Donations

Remember that part at the beginning about writing a check for your privilege? We can use our new toolkit to help make decisions about how to donate effectively! Whether you are donating money, time, skills, attention, or any way you are able, you probably want to use that resource effectively. 

You can become a [more effective donor](https://pacscenter.stanford.edu/research/effective-philanthropy-learning-initiative/donor-guide/) by identifying a **goal** you hope to achieve. Hopefully this tool has helped you identify an area you're especially interested in. For example, let's say your goal is to *decrease the probability of being low income among BIPOC people*.

Next, you can develop a [theory of change](https://www.theoryofchange.org/what-is-theory-of-change/), specific mechanisms that will help achieve your goal. Using Bayes' theorem to decompose the conditional probability of your goal then suggests possible mechanisms:
* Reducing the probability of being low income among BIPOC people (the posterior probability)
* Reducing the overall probability of being low income (the prior probability)
* Reducing the probability of being BIPOC among low income people (the likelihood)

What about the denominator of Bayes' theorem, the probability of being BIPOC? This may seem like a difficult measure to impact, but we can use the law of total probability to decompose this probability into different subgroups:

${tex`P(\text{BIPOC}) = P(\text{BIPOC | Low Income}) \cdot P(\text{Low Income}) + P(\text{BIPOC | Not Low Income}) \cdot P(\text{Not Low Income})`}

We can even substitute in different factors:

${tex`P(\text{BIPOC}) = P(\text{BIPOC | STEM Degree}) \cdot P(\text{Stem Degree}) + P(\text{BIPOC | No STEM Degree}) \cdot P(\text{No STEM Degree})`}

This suggests that you can work to reduce low income in BIPOC people in a variety of ways, such as increasing BIPOC people in STEM programs.  Will it have the largest possible impact on that specific probability? Probably not, but it will also have some impact on other outcomes too, and maybe you want to take a more general approach. It's your theory of change, and it's your money (or time, or attention, or whatever you have to give)! Perhaps the best lesson from Bayes' theorem is the simplest one: we are all dealing with uncertainty so we're not expecting a perfect answer - just a better one, now that we've learned more.
`
)}

function _24(md){return(
md`---`
)}

function _25(md){return(
md`## Sources
* All data is from the U.S. Census Bureau's [American Community Survey 5-Year Data](https://www.census.gov/data/developers/data-sets/acs-5year.2019.html) for 2015-2019. The data in this notebook is sourced from the [PUMS for WA file](https://depts.washington.edu/csscr/acs/acs5yr/) via University of Washington. 
* [How to build a Dynamic Bar Chart in Observablehq through sqlite3](https://towardsdatascience.com/how-to-build-a-dynamic-bar-chart-in-observablehq-through-sqlite3-f8f8b6509ac8) and [notebook](https://observablehq.com/@alod83/how-to-build-a-dynamic-bar-chart-through-sqlite3)`
)}

function _26(md){return(
md`---
##### Where the Sausage Gets Made`
)}

function _factor_options(){return(
new Map([
  ["Tech Worker", "tech"], 
  ["STEM Degree", "stem_related_degree"], 
  ["Bachelor Degree or Higher", "bach_degree_or_higher"],
  ["Age <35", "age_18_34"], 
  ["Non-BIPOC", "non_bipoc"],
  ["Male", "male"],
])
)}

function _labels(factor_options,sizes)
{
  let labels = [];
  for (const [key, value] of factor_options.entries()) {
    for (const s of sizes) {
      if (s === value) {
        labels.push(key);
      }
    }  
  }

  return labels.join(', ')
}


function _cf_labels(sizes)
{
  let labels = [];
  for (const s of sizes) {
    if (s == "tech") {
      labels.push("Non-Tech");
    }
    if (s == "stem_related_degree") {
      labels.push("Non-STEM");
    } 
    if (s == "bach_degree_or_higher") {
      labels.push("Less than Bachelor Degree");
    } 
    if (s == "age_18_34") {
      labels.push("Age 35+");
    } 
    if (s == "non_bipoc") {
      labels.push("BIPOC");
    } 
    if (s == "male") {
      labels.push("Non-Male");
    }
  }

  return labels.join(', ')
}


function _where_clause(sizes)
{
  let where = sizes[0] + " = 1"
  if (sizes.length > 1) {
    for (let index = 1; index < sizes.length; ++index) {
      where = where + " AND " + sizes[index] + " = 1";
    }
  }
  return where;
}


function _columns(sizes){return(
sizes.join(", ")
)}

function _comparison_where_clause(sizes)
{
  let where = sizes[0] + " = 0"
  if (sizes.length > 1) {
    for (let index = 1; index < sizes.length; ++index) {
      where = where + " AND " + sizes[index] + " = 0";
    }
  }
  return where;
}


function _33(md){return(
md`###### Data and Constants`
)}

function _data(db,combined_query){return(
db.query(combined_query)
)}

function _cf_data(db,comparison_query){return(
db.query(comparison_query)
)}

function _all_groups(db,all_groups_query){return(
db.query(all_groups_query)
)}

function _37(md){return(
md`###### Constants`
)}

function _cf_group_n(cf_data){return(
cf_data[0].value
)}

function _n_high_income(){return(
25817
)}

function _p_high_income(n){return(
25817/n
)}

function _n_low_income(){return(
311784
)}

function _p_low_income(n){return(
311784/n
)}

function _n_only(db){return(
db.query("select sum(PWGTP) from inc_table")
)}

function _n(n_only){return(
n_only[0]["sum(PWGTP)"]
)}

function _group_n(data){return(
data[0].value
)}

function _46(md){return(
md`###### Helper Functions`
)}

function _calcP(data,group_n){return(
function calcP(params) {
  let p = 0.0;
  for (let index = 0; index < data.length; ++index) {
    if (data[index]["name"] == params) {
      p = data[index]["value"] / group_n;
    }
  }
  return p;
}
)}

function _round4(){return(
function round4(n) {
  return Math.round(10000 * n) / 10000;
}
)}

function _calcPHighIncome(n_high_income,p_high_income,n){return(
function calcPHighIncome(input) {
  let p =  ((input.filter(d => d.name == "High Income")[0]["value"])/n_high_income) *
    p_high_income /
    (
      (((input.filter(d => d.name == "High Income")[0]["value"])/n_high_income) *
       p_high_income) +
      (((input.filter(d => d.name == "Not High Income")[0]["value"])/(n-n_high_income)) *
       (1 - p_high_income))
    );
  return p;
}
)}

function _calcPLowIncome(n_low_income,n){return(
function calcPLowIncome(input) {
  let p =  ((input.filter(d => d.name == "Low Income")[0]["value"])/n_low_income) *
    (n_low_income/n) /
    (
      (((input.filter(d => d.name == "Low Income")[0]["value"])/n_low_income) *
       (n_low_income/n)) +
      (((input.filter(d => d.name == "Not Low Income")[0]["value"])/(n-n_low_income)) *
       (1 - (n_low_income/n)))
    );
  return p;
}
)}

function _51(md){return(
md`###### Data Processing`
)}

function _db(FileAttachment){return(
FileAttachment("inc_counts_db@1").sqlite()
)}

function _53(db){return(
db.describe('inc_table')
)}

function _n_group_query(where_clause){return(
"SELECT 'All' as name,\n" +
"sum(CASE WHEN " + where_clause + " THEN PWGTP ELSE 0 END) as value,\n" + 
"1 as sort_order\n" +
"FROM inc_table"
)}

function _n_group_high_income_query(where_clause){return(
"SELECT 'High Income' as name,\n" +
"sum(CASE WHEN " + where_clause + " THEN PWGTP ELSE 0 END) as value,\n" + 
"2 as sort_order\n" +
"FROM inc_table WHERE high_income = 1"
)}

function _n_group_low_income_query(where_clause){return(
"SELECT 'Low Income' as name,\n" +
"sum(CASE WHEN " + where_clause + " THEN PWGTP ELSE 0 END) as value,\n" + 
"4 as sort_order\n" +
"FROM inc_table WHERE low_income = 1"
)}

function _n_group_not_high_income_query(where_clause){return(
"SELECT 'Not High Income' as name,\n" +
"sum(CASE WHEN " + where_clause + " THEN PWGTP ELSE 0 END) as value,\n" + 
"3 as sort_order\n" +
"FROM inc_table WHERE high_income = 0"
)}

function _n_group_not_low_income_query(where_clause){return(
"SELECT 'Not Low Income' as name,\n" +
"sum(CASE WHEN " + where_clause + " THEN PWGTP ELSE 0 END) as value,\n" + 
"5 as sort_order\n" +
"FROM inc_table WHERE low_income = 0"
)}

function _combined_query(n_group_query,n_group_high_income_query,n_group_not_high_income_query,n_group_low_income_query,n_group_not_low_income_query){return(
n_group_query + 
  "\nUNION\n" + 
  n_group_high_income_query +
  "\nUNION\n" + 
  n_group_not_high_income_query +
  "\nUNION\n" + 
  n_group_low_income_query +
  "\nUNION\n" + 
  n_group_not_low_income_query
)}

function _comparison_query(comparison_where_clause){return(
"SELECT 'All' as name,\n" +
"sum(CASE WHEN " + comparison_where_clause + " THEN PWGTP ELSE 0 END) as value,\n" + 
"1 as sort_order\n" +
"FROM inc_table" +
"\nUNION ALL\n" + 
"SELECT 'High Income' as name,\n" +
"sum(CASE WHEN " + comparison_where_clause + " THEN PWGTP ELSE 0 END) as value,\n" + 
"2 as sort_order\n" +
"FROM inc_table WHERE high_income = 1" + 
"\nUNION ALL\n" + 
"SELECT 'Not High Income' as name,\n" +
"sum(CASE WHEN " + comparison_where_clause + " THEN PWGTP ELSE 0 END) as value,\n" + 
"3 as sort_order\n" +
"FROM inc_table WHERE high_income = 0" +
"\nUNION ALL\n" + 
"SELECT 'Low Income' as name,\n" +
"sum(CASE WHEN " + comparison_where_clause + " THEN PWGTP ELSE 0 END) as value,\n" + 
"4 as sort_order\n" +
"FROM inc_table WHERE low_income = 1" +
"\nUNION ALL\n" + 
  "SELECT 'Not Low Income' as name,\n" +
"sum(CASE WHEN " + comparison_where_clause + " THEN PWGTP ELSE 0 END) as value,\n" + 
"5 as sort_order\n" +
"FROM inc_table WHERE low_income = 0"
)}

function _all_groups_query(){return(
"SELECT 'High Income' as name, sum(PWGTP) as value FROM inc_table WHERE high_income = 1" +
  "\nUNION\n" +
  "SELECT 'Not High Income' as name, sum(PWGTP) as value FROM inc_table WHERE high_income = 0" +
  "\nUNION\n" +
  "SELECT 'Low Income' as name, sum(PWGTP) as value FROM inc_table WHERE low_income = 1" +
  "\nUNION\n" +
  "SELECT 'Not Low Income' as name, sum(PWGTP) as value FROM inc_table WHERE low_income = 0" +
"\nUNION\n" +
  "SELECT 'Not High Income or Low Income' as name, sum(PWGTP) as value FROM inc_table WHERE low_income = 0 AND high_income = 0"
)}

function _62(md){return(
md`###### Imports`
)}

function _BS5(require){return(
require("https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.min.js")
)}

function _64(html){return(
html`<code>bootstrap.min.css</code> <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">`
)}

function _equity_map(FileAttachment){return(
FileAttachment("equity_map.png").image()
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  function toString() { return this.url; }
  const fileAttachments = new Map([
    ["inc_counts_db@1", {url: new URL("./files/1a39bf9e865bad998725805258f1a85473b13f1d3233c37f29026ed5a818d792be98c2a9f2158e88ef2283a6aac050e49c228aa5bfa7649193cd49e9d56c4b68", import.meta.url), mimeType: "application/x-sqlite3", toString}],
    ["equity_map.png", {url: new URL("./files/aa1c56a901bb34d2c5987eade9d14f9fc27625dab303052bdb6ed559f88f9e8f3f12cdf312ad40b522d2e6197317e4dddb70fb227eabc2958ba95e4950d819cf", import.meta.url), mimeType: "image/png", toString}]
  ]);
  main.builtin("FileAttachment", runtime.fileAttachments(name => fileAttachments.get(name)));
  main.variable(observer()).define(["md"], _1);
  main.variable(observer("viewof checkboxes")).define("viewof checkboxes", ["Inputs"], _checkboxes);
  main.variable(observer("checkboxes")).define("checkboxes", ["Generators", "viewof checkboxes"], (G, _) => G.input(_));
  main.variable(observer()).define(["equity_map","md"], _3);
  main.variable(observer()).define(["md"], _4);
  main.variable(observer("viewof sizes")).define("viewof sizes", ["Inputs","factor_options"], _sizes);
  main.variable(observer("sizes")).define("sizes", ["Generators", "viewof sizes"], (G, _) => G.input(_));
  main.variable(observer()).define(["labels","md"], _6);
  main.variable(observer("chart5")).define("chart5", ["BarChart","data","group_n","d3","width"], _chart5);
  main.variable(observer()).define(["cf_labels","md"], _8);
  main.variable(observer("chart6")).define("chart6", ["BarChart","cf_data","cf_group_n","d3","data","width"], _chart6);
  main.variable(observer()).define(["md"], _10);
  main.variable(observer()).define(["md"], _11);
  main.variable(observer()).define(["tex","md"], _12);
  main.variable(observer()).define(["md"], _13);
  main.variable(observer()).define(["Inputs","factor_options","viewof sizes"], _14);
  main.variable(observer()).define(["round4","p_high_income","labels","calcPHighIncome","data","cf_labels","cf_data","p_low_income","calcPLowIncome","md"], _15);
  main.variable(observer()).define(["md"], _16);
  main.variable(observer()).define(["tex","md"], _17);
  main.variable(observer()).define(["Inputs","factor_options","viewof sizes"], _18);
  main.variable(observer()).define(["round4","p_high_income","md"], _19);
  main.variable(observer()).define(["labels","data","n_high_income","cf_data","n","p_high_income","round4","calcPHighIncome","cf_labels","htl"], _20);
  main.variable(observer()).define(["round4","p_low_income","md"], _21);
  main.variable(observer()).define(["labels","data","n_low_income","cf_data","n","p_low_income","round4","calcPLowIncome","cf_labels","htl"], _22);
  main.variable(observer()).define(["tex","md"], _23);
  main.variable(observer()).define(["md"], _24);
  main.variable(observer()).define(["md"], _25);
  main.variable(observer()).define(["md"], _26);
  main.variable(observer("factor_options")).define("factor_options", _factor_options);
  main.variable(observer("labels")).define("labels", ["factor_options","sizes"], _labels);
  main.variable(observer("cf_labels")).define("cf_labels", ["sizes"], _cf_labels);
  main.variable(observer("where_clause")).define("where_clause", ["sizes"], _where_clause);
  main.variable(observer("columns")).define("columns", ["sizes"], _columns);
  main.variable(observer("comparison_where_clause")).define("comparison_where_clause", ["sizes"], _comparison_where_clause);
  main.variable(observer()).define(["md"], _33);
  main.variable(observer("data")).define("data", ["db","combined_query"], _data);
  main.variable(observer("cf_data")).define("cf_data", ["db","comparison_query"], _cf_data);
  main.variable(observer("all_groups")).define("all_groups", ["db","all_groups_query"], _all_groups);
  main.variable(observer()).define(["md"], _37);
  main.variable(observer("cf_group_n")).define("cf_group_n", ["cf_data"], _cf_group_n);
  main.variable(observer("n_high_income")).define("n_high_income", _n_high_income);
  main.variable(observer("p_high_income")).define("p_high_income", ["n"], _p_high_income);
  main.variable(observer("n_low_income")).define("n_low_income", _n_low_income);
  main.variable(observer("p_low_income")).define("p_low_income", ["n"], _p_low_income);
  main.variable(observer("n_only")).define("n_only", ["db"], _n_only);
  main.variable(observer("n")).define("n", ["n_only"], _n);
  main.variable(observer("group_n")).define("group_n", ["data"], _group_n);
  main.variable(observer()).define(["md"], _46);
  main.variable(observer("calcP")).define("calcP", ["data","group_n"], _calcP);
  main.variable(observer("round4")).define("round4", _round4);
  main.variable(observer("calcPHighIncome")).define("calcPHighIncome", ["n_high_income","p_high_income","n"], _calcPHighIncome);
  main.variable(observer("calcPLowIncome")).define("calcPLowIncome", ["n_low_income","n"], _calcPLowIncome);
  main.variable(observer()).define(["md"], _51);
  main.variable(observer("db")).define("db", ["FileAttachment"], _db);
  main.variable(observer()).define(["db"], _53);
  main.variable(observer("n_group_query")).define("n_group_query", ["where_clause"], _n_group_query);
  main.variable(observer("n_group_high_income_query")).define("n_group_high_income_query", ["where_clause"], _n_group_high_income_query);
  main.variable(observer("n_group_low_income_query")).define("n_group_low_income_query", ["where_clause"], _n_group_low_income_query);
  main.variable(observer("n_group_not_high_income_query")).define("n_group_not_high_income_query", ["where_clause"], _n_group_not_high_income_query);
  main.variable(observer("n_group_not_low_income_query")).define("n_group_not_low_income_query", ["where_clause"], _n_group_not_low_income_query);
  main.variable(observer("combined_query")).define("combined_query", ["n_group_query","n_group_high_income_query","n_group_not_high_income_query","n_group_low_income_query","n_group_not_low_income_query"], _combined_query);
  main.variable(observer("comparison_query")).define("comparison_query", ["comparison_where_clause"], _comparison_query);
  main.variable(observer("all_groups_query")).define("all_groups_query", _all_groups_query);
  main.variable(observer()).define(["md"], _62);
  main.variable(observer("BS5")).define("BS5", ["require"], _BS5);
  main.variable(observer()).define(["html"], _64);
  const child1 = runtime.module(define1);
  main.import("BarChart", child1);
  const child2 = runtime.module(define2);
  main.import("StackedBarChart", child2);
  main.variable(observer("equity_map")).define("equity_map", ["FileAttachment"], _equity_map);
  return main;
}
