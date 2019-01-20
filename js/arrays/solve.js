const json = {
	value: 10,
	children: [
		{
			value: 8,
			children: [
				{
					value: 4
				},
				{
					value: 3
				},
				{
					value: 2,
					children: [
						{
							value: 2
						}
					]
				}
			]
		},
		{
			value: 12,
			children: [
				{
					value: 6
				},
				{
					value: 5
				},
				{
					value: 6
				}
			]
		},
		{
			value: 4,
			children: [
				{
					value: 6
				},
				{
					value: 12
				},
				{
					value: 8
				}
			]
		}
	]
};

function func(_json) {
  if (!_json.children) return _json.value;
  const sumChildren = _json.children.reduce((prev, pres) => (prev + func(pres)), 0);
  return _json.value + sumChildren;
}

func(json);