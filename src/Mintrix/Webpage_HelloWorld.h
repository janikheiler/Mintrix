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

#ifndef MINTRIX_WEBPAGE_HelloWorld
#define MINTRIX_WEBPAGE_HelloWorld
namespace MintrixWeb
{

Webpage helloworld = {
  .page_html = "<h1>Hello World!</h1>",
  .style_css = "",
  .script_js = ""
};

}
#endif
