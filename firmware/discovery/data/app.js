fetch("/api/info")
.then(r=>r.json())
.then(j=>{

document.getElementById("info").innerHTML=`

<b>Chip:                                                                             </b> ${j.chip}<br>

<b>Cores: </b> ${j.cores}<br>

<b>Revision: </b> ${j.revision}<br>

<b>Flash: </b> ${j.flash} MB<br>

<b>SDK: </b> ${j.sdk}<br>

`;

});