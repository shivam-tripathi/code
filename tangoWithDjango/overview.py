'''
N tier architecture of web application
Client tier => Processing tier => Data Storage tier or Search API

Client is the web browser which will render the html and css page.
    Browser : Google chrome, Firefox, Safari, Opera, IE, Edge etc.
    Browser side languages : javascript (jquery), flash etc.
    Front-end framework : Bootstrap, Angularjs, CSS extention language (SASS,
        LESS, Stylus)

Middleware is the application (processing tier) hosted on a web server.
    Server side languages : PHP, JSP, ASP, Perl, Python, Ruby etc.
    Web servers : Apache, Nginx, Gunicorn, IIS etc.
    Web application framework :
        PHP framework : Laravel, CakePHP, CodeIgnitor, Prado, Symphony, Yii,
            Zend etc.
        JSP framework : Struts 2, JSF, Spring MVC, Wicket, etc.
        Python framework : Django, Grok, Pylos, TurboGears, web2py, Zope2 etc.
        Ruby framework : Camping, RubyOnRails, Ramaze etc.
        Google App Engine framework : webapp, webapp2 etc.
        MS ASP.net

Data storage uses the database engines to store data.
    Database : SQLite3, Postgres, MySQL, MS SQL, Oracle etc.

Search API like Google API, Bing API.

################################################################################

Framework
    It is a layered structure indicating what kind of programs can or should be
    built and how they would interrelate. It forces programmers to implement
    code in a way that promoted consistent coding, providing common libraries to
    facilitate and speed up the process.

    Framework is different from libraries. Programs call libraries, while frame
    work handles programs.
    For a web framework, it mostly handles http reequests and calls portion of
    the code as and when needed.
    Such an architecture is called handler callback pattern.

################################################################################

Wireframes
These are used to give an idea of how the application would look once they are
complete.

################################################################################

URL mappings have to be decided for related pages.

################################################################################

Entity realtionship diagram for Models
    For every given specification, there are two entities : category and page.
    One page can be in many categories, but it creates many complexities. So
    here we will use one to one model :
    A category may contain many pages, but a page can be assigned to only one
    category.

    Category - Page table and User table.

################################################################################

'''


