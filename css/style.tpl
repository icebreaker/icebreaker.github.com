body
{
	margin: 0;
	padding: 0 10px 10px 10px;
	-webkit-font-smoothing: antialiased;
	-moz-osx-font-smoothing: grayscale;
	text-rendering: optimizeLegibility;
	text-align: justify;
	text-justify: inter-word;
	font-family: -apple-system,BlinkMacSystemFont,Segoe UI,Roboto,sans-serif;
	font-size: 1.3rem;
	line-height: 2rem;
	background-color: $background;
	color: $foreground;
	max-width: 1024px;
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
  width: 16px;
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
}

h1, h2, h3, h4, h5, h6
{
	padding: 0;
	margin-bottom: 20px;
	margin-top: 20px;
	padding-bottom: 16px;
	border-bottom: 8px solid $highlight_light;
}

h2
{
	padding-bottom: 8px;
}

h3, h4, h5, h6
{
	padding-bottom: 4px;
}

p
{
	margin-top: 12px;
	margin-bottom: 12px;
}

blockquote
{
	margin: 0;
	padding: 10px;
	border-left: 8px solid $highlight_light;
	background-color: $highlight_dark;
}

code
{
	color: $highlight_foreground;
	font-weight: bolder;
	font-family: 'JetBrains Mono NL ExtraBold','Roboto Mono',monospace;
}

pre
{
	font-family: 'JetBrains Mono NL ExtraBold','Roboto Mono',monospace;
	overflow: auto;
	display: block;
	background-color: $highlight_dark !important;
	tab-size: 4;
	padding: 10px;
}

pre code
{
	font-family: 'JetBrains Mono NL ExtraBold','Roboto Mono',monospace;
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

img, iframe, .content video
{
	max-width: 1024px;
}

hr
{
	border: 4px solid $highlight_light;
	max-width: 320px;
}

table
{
	border-collapse: collapse;
	width: 100%;
	border-bottom: 8px solid $highlight_light;
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

.post-list table td
{
	white-space: nowrap;
	font-weight: bolder;
}

.post-list table td:last-child
{
	width: 100%;
}

.background
{
	opacity: 0.3;
	width: 100vw;
	height: 100vh;
	object-fit: cover;
	position: fixed;
	left: 0;
	right: 0;
	top: 0;
	bottom: 0;
	z-index: -1;
	display: none;
}

#music
{
	position: fixed;
	right: 30px;
	bottom: 30px;
	z-index: 9999;
	font-size: 48px;
	width: 320px;
	height: 180px;
	text-align: center;
	display: none;
}

#music a
{
	display: inline-block;
	margin-top: 66px;
}

#music iframe
{
	border: 8px $foreground solid;
}

@media only screen and (max-width: 1024px)
{
	body
	{
		font-size: 0.9rem;
		line-height: 1.6rem;
	}

	hr
	{
		max-width: 160px;
	}

	img, iframe, .content video
	{
		max-width: 100%;
	}
}

@media only screen and (min-width: 1280px)
{
	body
	{
		margin: 0 auto;
	}

	.background
	{
		display: block;
	}
}

@media only screen and (min-width: 1920px)
{
	body
	{
		margin: 0 auto;
	}

	#music
	{
		display: block;
	}
}

.image-diff-viewer
{
	position: relative;
	cursor: ew-resize;
	display: inline-block;
}

.image-diff-viewer img
{
	max-width: 1024px;
}

.image-diff-viewer img:last-child
{
	display: none;
}

.image-diff-viewer .wrapper
{
	position: absolute;
	width: auto;
	height: auto;
	top: 0;
	left: 0;
	overflow: hidden;
	border-right: 3px solid white;
	opacity: 0.8;
}

@media only screen and (max-width: 1024px)
{
	.image-diff-viewer img
	{
		max-width: 512px;
	}
}

@media only screen and (max-width: 512px)
{
	.image-diff-viewer img
	{
		max-width: 256px;
	}
}

.blood
{
	--blood: #BF0000;
}

.blood.poltergeist
{
	--blood: #7D7DFF;
}

.blood hr,
.blood h1,
.blood h2,
.blood h3,
.blood h4,
.blood h5,
.blood h6,
.blood table,
.blood blockquote
{
	border-color: var(--blood);
}

.blood a,
.blood a:active,
.blood a:visited,
.blood a:hover
{
	color: var(--blood);
}

.blood::-webkit-scrollbar-thumb:hover
{
	background: var(--blood);
}

.blood.nun .content:after
{
	content: url('/media/misc/13.png');
}

.blood #music iframe
{
	border: 8px var(--blood) solid;
}
