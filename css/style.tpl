body
{
	margin: 0;
	padding: 0 10px 10px 10px;
	-webkit-font-smoothing: antialiased;
	-moz-osx-font-smoothing: grayscale;
	text-rendering: optimizeLegibility;
	text-align: justify;
	text-justify: inter-word;
	font-family: sans-serif;
	font-size: 1.2rem;
	line-height: 2rem;
	background-color: $background;
	color: $foreground;
	max-width: 1024px;
	margin: 0 auto;
}

::-moz-selection
{
	background-color: $foreground;
	color: $background;
	font-weight: bolder;
}

::selection
{
	background-color: $foreground;
	color: $background;
	font-weight: bolder;
}

::-webkit-scrollbar
{
  width: 8px;
}

::-webkit-scrollbar-track
{
  background: $highlight_dark;
}

::-webkit-scrollbar-thumb
{
  background: $foreground;
}

::-webkit-scrollbar-thumb:hover
{
  background: $highlight_light;
}

:root
{
  scrollbar-color: $foreground $highlight_dark !important;
  scrollbar-width: 8px !important;
}

h1, h2, h3, h4, h5, h6
{
	padding: 0;
	margin-bottom: 5px;
	margin-top: 5px;
}

p
{
	margin-top: 12px;
	margin-bottom: 12px;
}

blockquote
{
	margin: 0;
	padding-left: 10px;
	border-left: 5px solid $foreground;
}

code
{
	padding: 2.5px 6.5px;
	font-weight: bolder;
	background-color: $foreground;
	color: $background;
}

pre
{
	font-family: monospace;
	overflow: auto;
	display: block;
	background-color: $highlight_dark !important;
	tab-size: 4;
	padding: 10px;
}

pre code
{
	font-family: monospace;
	font-weight: normal;
	tab-size: 4;
	padding: 0;
	color: $foreground;
	background-color: $highlight_dark !important;
}

a, a:active, a:visited, a:hover
{
	color: $highlight_light;
	text-decoration: none;
	font-weight: bolder;
}

a:hover
{
	text-decoration: underline;
}

img, iframe
{
	max-width: 1024px;
}

hr
{
	border: 3px solid $foreground;
	max-width: 320px;
}

table
{
	border-collapse: collapse;
	width: 100%;
	border-bottom: 5px solid $foreground;
}

table * tr th
{
	background-color: $highlight_dark;
	font-weight: bolder;
	text-align: left;
}

table * tr th, table * tr td
{
	padding: 10px;
}

table * tr:nth-child(even)
{
	background-color: $highlight_dark;
}

.nav
{
	font-weight: bolder;
	text-align: right;
}

.comments
{
	font-weight: bolder;
}

.post-list table
{
	width: auto;
}

.post-list table td
{
	white-space: nowrap;
	font-weight: bolder;
}

.post-list table td:last-child
{
	width: 100%;
}
