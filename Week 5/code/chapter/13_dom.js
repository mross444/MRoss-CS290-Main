function highlightCode(node, keywords) {
  var text = node.textContent;
  node.textContent = ""; // Clear the node

  var match, pos = 0;
  while (match = keywords.exec(text)) {
    var before = text.slice(pos, match.index);
    node.appendChild(document.createTextNode(before));
    var strong = document.createElement("strong");
    strong.appendChild(document.createTextNode(match[0]));
    node.appendChild(strong);
    pos = keywords.lastIndex;
  }
  var after = text.slice(pos);
  node.appendChild(document.createTextNode(after));
}

var languages = {
  javascript: /\b(function|return|var)\b/g /* … etc */
};

function highlightAllCode() {
  var pres = document.body.getElementsByTagName("pre");
  for (var i = 0; i < pres.length; i++) {
    var pre = pres[i];
    var lang = pre.getAttribute("data-language");
    if (languages.hasOwnProperty(lang))
      highlightCode(pre, languages[lang]);
  }
}

function buildTable(data) {
	var table = document.createElement("table");

	var fields = Object.keys(data[0]);
	var headRow = document.createElement("tr");
	fields.forEach(function(field) {
	  var headCell = document.createElement("th");
	  headCell.textContent = field;
	  headRow.appendChild(headCell);
	});
	table.appendChild(headRow);

	data.forEach(function(object) {
	  var row = document.createElement("tr");
	  fields.forEach(function(field) {
		var cell = document.createElement("td");
		cell.textContent = object[field];
		if (typeof object[field] == "number")
		  cell.style.textAlign = "right";
		row.appendChild(cell);
	  });
	  table.appendChild(row);
	});

	return table;
}