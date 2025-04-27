/* * * * * * * * * * * * * * * * * * * *
 *                                     *
 *            M I N T R I X            *
 *           by Janik Heiler           *
 *                                     *
 * * * * * * * * * * * * * * * * * * * */

#ifndef MINTRIXWEB
#define MINTRIXWEB
namespace MintrixWeb
{
    struct Webpage {
        String page_html;
        String style_css;
        String script_js;
    };
}
#endif

#ifndef MINTRIX_WEBPAGE_TextInput
#define MINTRIX_WEBPAGE_TextInput
namespace MintrixWeb
{

Webpage textinput = {
.page_html = R"=====(
<!DOCTYPE html>
<html>
	<head>
		<title>Mintrix</title>
		<meta charset='utf-8'>
		<link rel='shortcut icon' href='#'/>
		<link rel='stylesheet' type='text/css' href='/style.css'>
		<script type='text/javascript' src='/script.js'></script>
	</head>
	<body>
		<div id="wrapper">
			<input id="ipt" />
			<button id="btn" onclick="send()">Send!</button>
		</div>
	</body>
</html>

)=====",

.style_css = R"=====(
body {
    background-color: #333333;
}

#wrapper {
    position: absolute;
    left: 50%;
    top: 50%;
    transform: translate(-50%, -50%);
    width: 80%;
    max-width: 24rem;
}

#ipt {
    margin: 0 0 .2rem 0;
}

#ipt,
#btn {
    text-align: center;
    box-sizing: border-box;
    width: 100%;
    padding: .7rem .3rem;
}

)=====",

.script_js = R"=====(
function send() {
    xhr = new XMLHttpRequest();
    xhr.open('POST', '/data/?text=' + document.getElementById("ipt").value);
    xhr.setRequestHeader('Content-Type', 'text/plain');
    xhr.send();
}

)====="
};

}
#endif
 