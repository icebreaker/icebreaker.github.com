import os, doxter

class PostProcessor(doxter.Processor):
	def __init__(self):
		self.site = doxter.get_config()
		self.page = doxter.get_config('page')
		self.pages = []
		self.posts = []

		self.template = doxter.get_processor_by_name('TemplateProcessor')
		self.output = doxter.get_processor_by_name('OutputProcessor')

	def priority(self):
		return -2

	def process(self, root, extension, content):
		self.page.set('content', content)
		self.page.set('root', root)
		self.page.set('extension', extension)

		page_type = self.page.get('type')
		if page_type == 'page':
			self.pages.append(self.page.clone())
			return None
		elif page_type == 'post':
			self.posts.append(self.page.clone())

		return content

	def fake_process(self, page):
		root = page.get('root')
		extension = page.get('extension')
		content = page.get('content')

		self.page.replace(page)

		content = self.template.process(root, extension, content)
		return self.output.process(root, extension, content)

	def teardown(self):
		self.posts.reverse()

		self.site.set('posts', self.posts)
		self.site.set('pages', self.pages)

		for page in self.pages:
			self.fake_process(page)
