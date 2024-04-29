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

#ifndef MINTRIX_WEBPAGE_BigButton
#define MINTRIX_WEBPAGE_BigButton
namespace MintrixWeb
{

Webpage bigbutton = {
  .page_html = "<!DOCTYPE html><html><head><title>Mintrix</title><meta charset='utf-8'><link rel='shortcut icon' href='#'/><link rel='stylesheet' type='text/css' href='/style.css'><script type='text/javascript' src='/script.js'></script></head><body><button onclick='clicked()'>Drück mich!</button></body></html>",
  .style_css = "body {background: #000000;} button {font-size: 4rem; color: #000000; border: 1rem solid #ffffff; border-radius: 7.5rem; position: absolute; left: 50%; top: 50%; transform: translate(-50%, -50%); width: 80%; height: 80%;}",
  .script_js = "function clicked() {xhr = new XMLHttpRequest();xhr.open('POST', '/data/');xhr.setRequestHeader('Content-Type', 'text/plain');xhr.send();}"
};

}
#endif
