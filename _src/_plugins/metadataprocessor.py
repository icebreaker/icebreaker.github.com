import os, re, yaml, cgi, doxter
from datetime import date

def date_to_string(value, format='%B %d, %Y'):
	return value.strftime(format)

def date_to_xmlschema(value):
	return date_to_string(value, '%Y-%m-%dT00:00:00+02:00')

def xml_escape(value):
	return cgi.escape(value)

def array_to_sentence_string(array, connector='and'):
	l = len(array)
	if l == 0:
		return ''
	elif l == 1:
		return array[0]
	elif l == 2:
		return '%s %s %s' % (array[0], connector, array[1])
	else:
		return '%s, %s %s' % (', '.join(array[:-1]), connector, array[-1])

class MetadataProcessor(doxter.Processor):
	def __init__(self):
		self.regexp_pygments = re.compile(r'\{%\s+highlight\s+(.*?)\s+%\}(.*?)\{%\s+endhighlight\s+%\}', re.S)
		self.regexp_metadata = re.compile(r'^---\s+(.*?)\s+---', re.S)
		self.regexp_path = re.compile(r'^(.*?)\-(.*?)\-(.*?)\-(.*?)$')
		self.page = doxter.get_config('page')

		self.template = doxter.get_processor_by_name('TemplateProcessor')
		self.template.register_filter('date_to_string', date_to_string)
		self.template.register_filter('date_to_xmlschema', date_to_xmlschema)
		self.template.register_filter('xml_escape', xml_escape)
		self.template.register_filter('array_to_sentence_string', array_to_sentence_string)

	def priority(self):
		return 1

	def process(self, root, extension, content):
		basename = self.page.get('basename')
		content = re.sub(self.regexp_pygments, lambda m: self.wrap_highlight(m.group(1), m.group(2)), content)
		return re.sub(self.regexp_metadata, lambda m: self.wrap_metadata(basename, extension, m.group(1)), content)

	def wrap_metadata(self, basename, extension, content):
		self.page.update(**yaml.load(content))
		self.page.set('template', self.page.get('layout'))

		path = re.match(self.regexp_path, basename)
		if path:
			d = [int(path.group(1)), int(path.group(2)), int(path.group(3))]

			url = '%d/%d/%d/%s' % tuple(d + [path.group(4)])
			self.page.set('path', url)
			self.page.set('url', url)
			self.page.set('type', 'post')
			self.page.set('filename', 'index.html')
			self.page.set('date', date(*d))
		else:
			if extension in ['.md', '.markdown', '.mdown']:
				self.page.set('path', basename)
				self.page.set('url', basename)
				self.page.set('filename', 'index.html')
			else:
				self.page.set('filename', basename + extension)

			self.page.set('date', date.today())
			self.page.set('type', 'page')

		return ''

	def wrap_highlight(self, lexer, content):
		return '```%s\n%s\n```' % (lexer, content)
