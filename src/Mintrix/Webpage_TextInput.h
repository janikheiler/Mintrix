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
  .page_html = "<h1>Textinput!</h1>",
  .style_css = "",
  .script_js = ""
};

}
#endif
